#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Prefer to use std::lock_guard than to use std::unique_lock,
// since std::unique_lock has larger overhad. Except:

// 1. Would like to use std::defer_lock
class A {
 private:
  int a_;
  std::mutex m_;

 public:
  friend void swap(A& lhs, A& rhs) {
    if (&lhs == &rhs) return;
    std::unique_lock<std::mutex> lhs_lock(lhs.m_, std::defer_lock);  // associate with mutex but not lock it
    std::unique_lock<std::mutex> rhs_lock(rhs.m_, std::defer_lock);  // associate with mutex but not lock it
    std::lock(lhs_lock, rhs_lock);  // lock std::unique_lock instead of mutex
    std::swap(lhs.a_, rhs.a_);
  }
};

// 2. Would like to transfer the ownership of locks from one scope to another
std::mutex m1;
std::unique_lock<std::mutex> get_lock() {
  std::unique_lock<std::mutex> lock(m1);
  // prepare data
  return lock;
}

// 3. Would like to lock/unlock at an appropriate granularity
class B {
 private:
  int a_;
  std::mutex m_;

 public:
  friend bool operator==(B& lhs, B& rhs) {
    if (&lhs == &rhs) return true;
    std::unique_lock<std::mutex> lhs_lock(lhs.m_);
    int lhs_a = lhs.a_;
    lhs_lock.unlock();  // release lock immediately after reading value

    std::unique_lock<std::mutex> rhs_lock(rhs.m_);
    int rhs_a = rhs.a_;
    rhs_lock.unlock();  // release lock immediately after reading value
    return lhs_a == rhs_a;  // compare values of that time, not current time?
  }
};

int main() {
  A a1, a2;
  std::thread t1([&a1, &a2]() { swap(a1, a2); });
  std::thread t2([&a1, &a2]() { swap(a2, a1); });
  t1.join();
  t2.join();

  B b1, b2;
  std::thread t3([&b1, &b2]() { return b1 == b2; });
  std::thread t4([&b1, &b2]() { return b1 == b2; });
  t3.join();
  t4.join();
}
