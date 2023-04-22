#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct A {
  void foo() {}
};

struct B {
  void foo() {}
};


// variadic macro
#define G(a, ...) \
vector<int*> ta;  \
void x() { ta = {__VA_ARGS__}; }


// variadic function
template <typename... T>
void F(T&... t) {
  // cout << __PRETTY_FUNCTION__ << "\n";
  constexpr int sizet = sizeof...(t);
  cout << sizet << endl;
  int x[sizet] = {(t.foo(), 0)...};
}

// variadic struct
template <class... Ts>
struct S {};

template <class T, class... Ts>
struct S<T, Ts...> : S<Ts...> {
  S(T t, Ts... ts) : S<Ts...>(ts...), tail(t) {}

  T tail;
};


int main() {
  A a;
  B b;
  F(a, b);

  S<int, int> s(1 , 1);
}
