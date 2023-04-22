#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>

// Three ways to avoid problematic race condition:
// 1. mutex, mutal exclusive, a synchronization primitive
// 2. lock-free programming
// 3. software transactional memory (STM)

int x = 0;
std::mutex x_mutex;

void f1() {
  std::this_thread::sleep_for(std::chrono::milliseconds(2));
  x_mutex.lock();
  x = 1;
  x_mutex.unlock();  // manually release x_mutex, which is not recommended
}

void f2() {
  std::lock_guard<std::mutex> lock(x_mutex);
  x = 2;
  // x_mutex is auto released when lock goes out of scope
}

// clang -pthread
int main() {
  std::thread t1(f1);
  std::thread t2(f2);
  t1.join();
  t2.join();
  std::cout << x << std::endl;  // 1

  std::cout << "main thread exits" << std::endl;
  return 0;
}