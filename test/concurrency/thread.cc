#include <thread>
#include <iostream>
#include <string>
#include <vector>


void foo(int a) {
  std::cout << "foo number a: " << a << std::endl;
}

void bar(const int& a) {
  std::this_thread::sleep_for(std::chrono::milliseconds(20));
  std::cout << "bar number a: " << a << std::endl;
}

void pose(std::string& s) {
  s = "hello";
}

struct A {
  void a_func() {
    std::cout << "A::a_func" << std::endl;
  }
};

void back() {
  std::cout << "finish back" << std::endl;
}

// clang -pthread
int main() {
  std::cout << "Number of threads: " << std::thread::hardware_concurrency() << std::endl;
  std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
  std::cout << "yield " << std::endl; std::this_thread::yield();
  std::cout << std::endl;

  std::thread t1(foo, 1);
  t1.join();
  std::cout << std::endl;

  int a = 2;
  std::thread t2(bar, a);  // a is copied into thread t2, despite of bar expects a reference.
  ++a;
  t2.join();
  std::cout << "main number a: " << a << std::endl;
  std::cout << std::endl;

  std::string s("world");
  std::cout << "main s: " << s << std::endl;
  std::thread t3(pose, std::ref(s));  // s is referred by t3, so pose could modify s
  t3.join();
  std::cout << "main s: " << s << std::endl;
  std::cout << std::endl;

  A x;
  std::thread t4(&A::a_func, &x);  // pass member method to thread
  t4.join();
  std::cout << std::endl;

  std::thread t5(back);
  t5.detach();  // t5 does not own a thread anymore
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << std::endl;

  std::cout << "main thread exits" << std::endl;
  return 0;
}