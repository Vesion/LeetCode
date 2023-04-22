#include <iostream>

// A function only accepts rvalue
// `x` is a lvalue, its type is rvalue reference
void f(int&& x) {
  std::cout << x << std::endl;
}

// A template function accepts both lvalue and rvalue
// `x` is a lvalue, its type is:
//   lvalue reference if receives a lvalue argument
//   rvalue reference if receives a rvalue argument
// This is called a forwarding reference or a universal reference
template<typename T>
void g(T&& x) {
  std::cout << x << std::endl;
}

template<typename T>
void h(T&& x) {
  g(std::forward<T>(x));  // perfect forwarding
}

int main() {
  int a = 1;
  const int b = 2;

  // Bind lvalue reference to lvalue
  int& lra = a;  // non-const lvalue reference binds to a non-const lvalue
  const int& clra = a;  // const lvalue reference binds to a non-const lvalue
  // int& lrb = b;  // Error, non-const lvalue reference cannot bind to a const lvalue
  const int& clrb = b;  // const lvalue reference binds to a const lvalue

  // Bind lvalue reference to rvalue
  // int& lr1 = 1;  // Error, non-const lvalue reference cannot bind to a rvalue
  const int& lr1 = 1;  // const lvalue reference binds to a rvalue

  // Bind rvalue reference to rvalue
  int&& rr1 = 1;  // non-const rvalue reference binds to a rvalue
  const int&& crr1 = 1;  // const rvalue reference binds to a rvalue

  // Bind rvalue reference to lvalue
  // Error, rvalue reference cannot bind to lvalue
  // int&& rra = a;
  // const int&& crra = a;
  // int&& rrb = b;
  // const int&& crrb = b;

  // f(a);  // Error, rvalue reference cannot bind to lvalue
  // f(b);  // Error, rvalue reference cannot bind to const lvalue
  f(1);

  g(a);
  g(b);
  g(1);

  h(a);
  h(b);
  h(1);
}