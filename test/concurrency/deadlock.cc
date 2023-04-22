#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>


// Guideline to avoid deadlock
// 1. avoid nested locks, each thread only holds at most a single lock
// 2. avoid calling user code while hoding a lock (user code might have been holding locks)
// 3. acquire locks in a fixed order, std::lock
// 4. use a lock hierarchy, ensure a thread is joined in the same function that started it

class A {
 private:
  int a_;
  std::mutex m_;

 public:
  friend void dead_swap(A& lhs, A& rhs) {
    if (&lhs == &rhs) return;
    std::lock_guard<std::mutex> lhs_lock(lhs.m_);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> rhs_lock(rhs.m_);
    std::swap(lhs.a_, rhs.a_);  // could never reach here due to deadlock
  }

  friend void swap(A& lhs, A& rhs) {
    if (&lhs == &rhs) return;
    std::lock(lhs.m_, rhs.m_);  // lock two mutexes without deadlock happening
    std::lock_guard<std::mutex> lhs_lock(lhs.m_, std::adopt_lock);  // acquire ownership of mutex without atempting to lock it
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> rhs_lock(rhs.m_, std::adopt_lock);  // acquire ownership of mutex without atempting to lock it
    std::swap(lhs.a_, rhs.a_);
  }
};

int main() {
  A a1;
  A a2;

  // std::thread t1([&a1, &a2]() { dead_swap(a1, a2); });  // acquire a1.m firstly, wait for a2.m being released
  // std::thread t2([&a1, &a2]() { dead_swap(a2, a1); });  // acquire a2.m firstly, wait for a1.m being released
  // t1.join();
  // t2.join();

  std::thread t3([&a1, &a2]() { swap(a1, a2); });
  std::thread t4([&a1, &a2]() { swap(a2, a1); });
  t3.join();
  t4.join();

  return 0;
}