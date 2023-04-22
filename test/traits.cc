#include <iostream>
#include <type_traits>

// C++17 provides std::void_t though
template<class...>
using void_t = void;


#define HAS_MEMBER_FUNC(func_name)             \
  template<typename, typename = void>          \
  struct has_##func_name : std::false_type {}; \
  template<typename T>                         \
  struct has_##func_name<T, void_t<decltype(&T::func_name)>> : std::true_type {};


HAS_MEMBER_FUNC(clear);

template <typename T,
          typename = std::enable_if_t<has_clear<T>::value>>
void reset_fields(T& field) {
  field.clear();  // No type traits check here. Because unexpect other means of clear.
}

struct A {
  void clear() {}
};

struct B {

};

int main() {
  A a;
  B b;
  reset_fields(b);
}
