#include <iostream>

// https://stackoverflow.com/questions/3582001/advantages-of-using-forward

void foo(int x) {}

template <typename T>
void bar(T&& x) {
  foo(std::forward<T>(x));
  // foo(static_cast<T&&>(x));
}

int main() {
  foo(1);
  bar(1);

  int x = 1;
  foo(x);
  bar(x);
}