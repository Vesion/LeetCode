#include <iostream>
using namespace std;


int x;
template<class T>
class B {
public:
  B() {
    x = 1;
  }
};

class A {
  static B<int> b;
};

B<int> A::b;

int main() {
  cout << x << endl;
}
