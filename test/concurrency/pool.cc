#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <deque>

#define CHECK(exp) \
do { \
  if (!(exp)) { \
    std::cout << "unexpected abort" << std::endl; \
    std::abort(); \
  } \
} while (false)

void foo(int a) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "foo thread id: " << std::this_thread::get_id() << std::endl;
  std::cout << "print number: " << a << std::endl;
}

std::mutex g_mutex;
int g = 0;
void mutex_foo(int a) {
  const std::lock_guard<std::mutex> lock(g_mutex);
  g += a;
  std::cout << "g: " << g << std::endl;
}

class thread_pool {
 public:
  thread_pool(int num_threads) {
    for (int i = 0; i < num_threads; ++i) {
      pool_.emplace_back([this]() { Loop(); });
    }
  }

  virtual ~thread_pool() {
    {
      std::lock_guard<std::mutex> lock(mutex_);
      CHECK(queue_.empty() && working_items_ == 0);  // there's still working items
    }
    ShutDone();
  }

  // Cancel all waiting threads, but wait already-started works done.
  void ShutDone() {
    {
      std::lock_guard<std::mutex> lock(mutex_);
      if (!running_) {
        return;
      }
      queue_.clear();
      running_ = false;  // terminate pending threads
    }

    cv_waiting_for_work_.notify_all();
    cv_waiting_for_done_.notify_all();
    for (std::thread& thread : pool_) {  // wait already-started works done
      thread.join();
    }

    {
      std::lock_guard<std::mutex> lock(mutex_);
      working_items_ = 0;
    }
  }

  void WaitForAllWorksDone() {
    {
      std::unique_lock<std::mutex> lock(mutex_);
      cv_waiting_for_done_.wait(lock, [this]() { return queue_.empty() && working_items_ == 0; });
    }
  }

  void Schedule(std::function<void(int)> work_item, int param) {
    auto t = std::bind(work_item, param);
    {
      std::lock_guard<std::mutex> lock(mutex_);
      CHECK(running_);
      queue_.push_back(t);
    }
    cv_waiting_for_work_.notify_one();
  }

 private:
  void Loop() {
    for (;;) {
      std::function<void()> work_item;
      {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_waiting_for_work_.wait(lock, [this]() { return !queue_.empty() || !running_; });
        if (!running_) {
          break;
        }
        work_item = queue_.front();
        queue_.pop_front();
        working_items_++;
      }
      CHECK(work_item);
      work_item();
      {
        std::unique_lock<std::mutex> lock(mutex_);
        working_items_--;
        if (queue_.empty() && working_items_ == 0) {
          lock.unlock();
          cv_waiting_for_done_.notify_all();
        }
      }
    }
  }

  std::mutex mutex_;
  std::vector<std::thread> pool_;
  std::deque<std::function<void()>> queue_;
  std::condition_variable cv_waiting_for_work_;  // to notify a waiting thread to start a work
  std::condition_variable cv_waiting_for_done_;  // to notify current thread when all works done
  bool running_ = true;  // to terminate all threads
  int working_items_ = 0;  // +1 before work starting, -1 after work done
};

// clang -pthread
int main() {
  // std::cout << "Number of threads: " << std::thread::hardware_concurrency() << std::endl;
  // std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

  // // spawn threads
  // std::thread t1(foo, 1);
  // std::thread t2(foo, 2);
  // // wait threads done
  // t1.join();
  // t2.join();

  // // mutex
  // std::thread mt1(mutex_foo, 1);
  // std::thread mt2(mutex_foo, 2);
  // mt1.join();
  // mt2.join();

  // // future
  // std::packaged_task<int()> task([]{ return 7; });
  // std::future<int> f1 = task.get_future();
  // // task();  // from a syncronized thread
  // std::thread t3(std::move(task));  // from an async thread
  // t3.join();
  // std::cout << "future: " << f1.get() << std::endl;  // wait and retrieve value

  // thread pool
  thread_pool tp(10);
  auto f = [](int i) { std::cout << "thread pool " << i << std::endl; };

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      tp.Schedule(f, j);
    }
    tp.WaitForAllWorksDone();
    std::cout << "thread pool done" << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  std::cout << "done" << std::endl;
  return 0;
}