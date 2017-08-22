#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 裴蜀定理的应用

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int cases; cin >> cases;
    while (cases--) {
        int L, F, D; 
        cin >> L >> F >> D;
        if (gcd(L, D) >= F)  // gcd(L, D) is the minimum gap in the whole walk
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}

