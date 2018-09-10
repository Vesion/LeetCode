#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long fastPow(int x, int n) {
    long long result = 1, tmp = x;
    while (n) {
        if (n & 1) result *= tmp;
        tmp *= tmp;
        n >>= 1;
    }
    return result;
}

long long fastPowMod(int x, int n, int mod = 1) {
    long long result = 1, tmp = x;
    while (n) {
        if (n & 1) result = (result * tmp) % mod;
        tmp = (tmp * tmp) % mod;
        n >>= 1;
    }
    return result % mod;
}


int main() {
    cout << fastPow(2, 6) << endl; 
    cout << fastPowMod(2, 6, 3) << endl; 
    return 0;
}
