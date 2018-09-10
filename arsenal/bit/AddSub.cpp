#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem: use bit manipulation to implement addition (or substraction)


int add(int a, int b) {
    while (b) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}


int sub(int a, int b) {
    while (b) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}



int main() {
    cout << add(99, 123) << endl; 
    cout << sub(12, 90) << endl;
    return 0;
}
