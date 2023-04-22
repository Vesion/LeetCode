#include <iostream>
#include <vector>

struct S {
  // Non user-provided default ctor.
  // As a result, the default ctor is implicitly defined.
  int f1 = 2;
  int f2;
};

struct R {
  // Non user-provided default ctor.
  // "defaulted" default ctor
  R() = default;
  int f1 = 2;
  int f2;
};

struct P {
  // User-provided ctor.
  // f1 and f2 are value-initialized.
  P() : f1(2), f2() {}

  int f1;
  int f2;
};

int main() {
  // default-init
  // if has user-provided default ctor, call it;
  // otherwise applay default-init to all fields
  std::cout << "default-init" << std::endl;
  {
    S s;
    std::cout << s.f1 << " " << s.f2 << std::endl;  // 2, dirty-value

    S* s2 = new S;
    std::cout << s2->f1 << " " << s2->f2 << std::endl;  // 2, dirty-value

    P p;
    std::cout << p.f1 << " " << p.f2 << std::endl;  // 2, 0
  }

  // value-init
  // if user-provided default ctor, call it;
  // otherwise firstly zero-init then applay default-init to all fields
  std::cout << "value-init" << std::endl;
  {
    // value-init a named object before c++11,
    // actually it value-init a temporary object then copy-init a3,
    // but the copy-init is opt out through copy-elision
    R r = R();
    std::cout << r.f1 << " " << r.f2 << std::endl;  // 2, 0

    R* r2 = new R();
    std::cout << r2->f1 << " " << r2->f2 << std::endl;  // 2, 0

    // error, it declares a function that takes no arguments and returns R
    // R r3();

    P p = P{};
    std::cout << p.f1 << " " << p.f2 << std::endl;  // 2, 0
    P p2{};
    std::cout << p2.f1 << " " << p2.f2 << std::endl;  // 2, 0
    P* p3 = new P{};
    std::cout << p3->f1 << " " << p3->f2 << std::endl;  // 2, 0
  }

  return 0;
}


