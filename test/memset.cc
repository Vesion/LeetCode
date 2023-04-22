#include <iostream>
#include <cstring>
void Bar(int* arr);
void Test() {
  int foo[3];
  std::memset(foo, 0, sizeof(foo));
  Bar(foo);
}