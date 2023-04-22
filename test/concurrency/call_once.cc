#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

std::unique_ptr<int[]> resource_ptr;
std::mutex resource_m;
std::once_flag resource_flag;

void undefined_behavior_with_double_checked_locking_init_resource() {
  if (!resource_ptr) {
    std::lock_guard<std::mutex> lock(resource_m);
    if (!resource_ptr) {
      resource_ptr.reset(new int[10]{0});
    }
  }
  resource_ptr[0] = 1;  // this line could be undefined behavior since the first check isn't synchronized with write
}

void init_resource() {
  std::cout << "init resource" << std::endl;
  resource_ptr.reset(new int[10]{0});
  resource_ptr[0] = 1;
}

void foo() {
  std::call_once(resource_flag, init_resource);
}

int main() {
  std::thread t1(foo);
  std::thread t2(foo);
  t1.join();
  t2.join();
}