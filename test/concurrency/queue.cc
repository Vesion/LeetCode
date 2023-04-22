#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <queue>



template <typename T>
class ThreadsafeQueue {
 public:
  ThreadsafeQueue() = default;
  ~ThreadsafeQueue() = default;
  ThreadsafeQueue(const ThreadsafeQueue& rhs) {
    std::lock_guard<std::mutex> lock(rhs.m_);  // note lock rhs's mutex
    data_ = rhs.data_;
  }
  ThreadsafeQueue& operator=(const ThreadsafeQueue&) = delete;

  bool empty() const {
    std::lock_guard<std::mutex> lock(m_);
    return data_.empty();
  }

  void push(const T& value) {
    std::shared_ptr<T> entry = std::make_shared<T>(value);
    std::lock_guard<std::mutex> lock(m_);
    data_.push(entry);
    cond_.notify_one();
  }

  bool try_pop(T& value) {
    std::lock_guard<std::mutex> lock(m_);
    if (data_.empty()) {
      return false;
    }
    value = std::move(*data_.front());
    data_.pop();
    return true;
  }
  std::shared_ptr<T> try_pop() {
    std::lock_guard<std::mutex> lock(m_);
    if (data_.empty()) {
      return nullptr;
    }
    auto result = data_.front();
    data_.pop();
    return result;

  }

  void wait_and_pop(T& value) {
    std::unique_lock<std::mutex> lock(m_);
    cond_.wait(lock, [this]{ return !data_.empty(); });
    value = std::move(*data_.front());
    data_.pop();
  }
  std::shared_ptr<T> wait_and_pop() {
    std::unique_lock<std::mutex> lock(m_);
    cond_.wait(lock, [this]{ return !data_.empty(); });
    auto result = data_.front();
    data_.pop();
    return result;
  }


 private:
  // Benefits of storing std::shared_ptr<T> rather than T:
  // 1. If std::make_shared<T> throws an exception when pop, none of other threads will be woken
  // 2. The allocation of the new instance can now be done outside the lock in push()
  std::queue<std::shared_ptr<T>> data_;
  mutable std::mutex m_;
  std::condition_variable cond_;
};

int main() {
  ThreadsafeQueue<int> q;

  std::thread t1([&q]() {
    static int d = 0;
    while (true) {
      q.push(d++);
    }
  });
  std::thread t2([&q]() {
    while (true) {
      std::cout << *q.wait_and_pop() << std::endl;
    }
  });
  std::thread t3([&q]() {
    while (true) {
      int d;
      if (q.try_pop(d)) {
        std::cout << d << std::endl;
      }
    }
  });

  t1.join();
  t2.join();
  t3.join();
}