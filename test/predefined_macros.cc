#include <iostream>

void foo() {
  std::cout << __func__ << std::endl;  // __func__ is not a macro, but a local variable
}


int main() {
  foo();
  std::cout << __LINE__ << std::endl;
  std::cout << __FILE__ << std::endl;
  std::cout << __DATE__ << std::endl;
  std::cout << __TIME__ << std::endl;
  std::cout << __cplusplus << std::endl;
  std::cout << __STDC__ << std::endl;
  std::cout << __STDC_HOSTED__ << std::endl;
  // std::cout << __STDCPP_THREADS__ << std::endl;
  return 0;
}