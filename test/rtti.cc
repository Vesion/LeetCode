#include <iostream>
#include <typeinfo>

// A class must have at least one virtual functoin to become a polymorphic.
class A {
 public:
  virtual ~A() = default;
};

class B : public A {
};

// The typeid keyword is used to determine the class of an object at run time.
// It returns a reference to std::type_info object, which exists until the end of the program.
int main() {
  A a;
  B b;
  A* pa = &b;
  A& ra = b;

  std::cout << typeid(a).name() << std::endl; // 1A, statically known in compile time
  std::cout << typeid(b).name() << std::endl; // 1B, statically known in compile time
  std::cout << typeid(pa).name() << std::endl;  // P1A, statically known in compile time
  std::cout << typeid(*pa).name() << std::endl;  // 1B, looked up dynamically at run-time
                                                 // because it is the dereference of a
                                                 // pointer to a polymorphic class
  std::cout << typeid(ra).name() << std::endl;  // 1B, references can also be polymorphic

}
