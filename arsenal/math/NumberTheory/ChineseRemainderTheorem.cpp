#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Description:
//      Given two arrays, [a0, a1, a2, ..., ai], and [m0, m1, m2, ..., mi] (any of two mi are coprime)
//      The equations group:
//
//          x = a0 mod m0
//          x = a1 mod m1
//          ...
//          x = ai mod mi
//
//      has roots, and has unique root x when mod M = m1 * m2 * ... * mi
//
//          x = (a1*M1*N1 + a2*M2*N2 + ... + ai*Mi*Ni) mod M
//          where Mi = M/mi, Ni is the mod m[i] inverse of Mi (Mi*Ni = 1 mod m[i])


void extend_Euclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a/b*y;
}

int CRT(int a[], int m[], int n) {
    int M = 1;
    int result = 0;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    for (int i = 0; i < n; ++i) {
        int x, y;
        int Mi = M / m[i];
        extend_Euclid(Mi, m[i], x, y); // x 是Mi模mi的逆元
        result = (result + a[i] * Mi * x) % M;
    }
    if (result < 0) result += M;
    return result;
}


int main() {
    int a[3] = {2, 3, 2};
    int m[3] = {3, 5, 7};
    cout << CRT(a, m, 3) << endl; // 23
    return 0;
}
