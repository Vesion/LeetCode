#include <iostream>
#include <vector>
#include <map>

class A {
 public:
  A() {
    std::cout << "ctor" << std::endl;
  }
  A(const A& a) : x(a.x) {
    std::cout << "copy ctor" << std::endl;
  }
  A& operator=(const A& a) {
    std::cout << "copy =" << std::endl;
    x = a.x;
    return *this;
  }
  A(A&& a) : x(std::move(a.x)) {
    std::cout << "move ctor" << std::endl;
  }
  A& operator=(A&& a) {
    std::cout << "move =" << std::endl;
    x = std::move(a.x);
    return *this;
  }

  std::string x = "123";
};

class B {
 public:
  B(A&& aa) : a(std::move(aa)) {}
  A a;
};

A getA() {
  A a;
  a.x = "1";
  return a;
}

void setA(A a) {
  a.x = "a";
  return;
}

void setMoveA(A a) {
  A a1 = std::move(a);
  return;
}

std::vector<A> v;
A getAA() {
  A a;
  v.push_back(std::move(a));
  return v[0];
}

int main() {
  {
    A a0;  // ctor
    A a1(getA());  // ctor, NamedRVO
    A a2 = getA();  // ctor, NamedRVO

    A a3(a1);  // copy ctor
    a3 = getA();  // ctor, move =
    a3 = a1;  // copy =

    A a4(std::move(a1));  // move ctor
    a4 = std::move(a1);  // move =

    setA(a1);  // copy ctor
    setA(std::move(a1));  // move ctor

    setMoveA(a0);  // copy ctor, move ctor
    setMoveA(std::move(a0));  // move ctor, move ctor

    const A a5;  // ctor
    A a6(std::move(a5));  // copy actor, due to a5 is const
    a6 = std::move(a5);  // copy =, due to a5 is const
  }
}
