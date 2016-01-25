#include <iostream>
using namespace std;

// binary multiply

// recursive, top-down
double myPow_topdown(double x, int n) {
    if (n == 0)
        return 1;
    if (n < 0) {
        if (n == INT_MIN)
            return myPow_topdown(x, n / 2) * myPow_topdown(x, n / 2);
        return 1 / myPow_topdown(x, -n);
    }
    if (n == 1)
        return x;
    if (n & 1)
        return myPow_topdown(x, n - 1) * x;
    else
        return myPow_topdown(x * x, n / 2);
}

// bottom up
double myPow_bottomup(double x, int n) {
    if (n == 0)
        return 1;
    if (n < 0) {
        if (n == INT_MIN)
            return myPow_bottomup(x, n / 2) * myPow_bottomup(x, n / 2);
        return 1 / myPow_bottomup(x, -n);
    }
    double tmp = x;
    double result = 1;
    while (n) {
        if (n & 1)
            result *= tmp; 
        tmp *= tmp;
        n >>= 1;
    }
    return result;
}


int main() {
    cout << myPow_topdown(1, INT_MIN) << endl;
    cout << myPow_bottomup(2, 7) << endl;
    return 0;
}
