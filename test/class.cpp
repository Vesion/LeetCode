#include <iostream>
#include <vector>
using namespace std;

class B;

class A {
public:
    int i1;
    char c1;
    float f1;
    double d1;
    B *b1; // must be a pointer, otherwise incomplete type error
};

class B {
public:
    int i2;
};

int main() {
    A a;
    B b;
    cout << a.i1 << endl;
    cout << b.i2 << endl;
    return 0;
}
