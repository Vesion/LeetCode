#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// use only addition + to implement division /, doubling
int divide(int A, int B) {
    if (B == 0 || (A == INT_MIN && B == -1)) return INT_MAX;
    unsigned a = abs(A), b = abs(B), res = 0;
    while (a >= b) {
        unsigned sum = b, count = 1;
        while (sum < (INT_MAX>>1) && sum + sum <= a) {
            sum += sum;
            count += count;
        }
        a -= sum;
        res += count;
    }
    return (A > 0) == (B > 0) ? res : -res;
}


int main() {
    return 0;
}

