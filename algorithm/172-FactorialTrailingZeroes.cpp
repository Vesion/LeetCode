#include <iostream>
using namespace std;

// same with 'Beauty of Programming' Problem2.2
// due to one 2 factor and one 5 factor can generate one 0, so find all 5 factors (which much more than 2 factors)

// Solution 0 : judege one by one with mod 5, O(n) time, TLE
int trailingZeroes_mod(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j%5 == 0) { ++count; j /= 5; }
    }
    return count;
}


// Solution 1 : formula : count = [n/5] + [n/(5^2)] + [n/(n^3)] + ...
// 1...n中，每个5的倍数提供一个5，每个5^2的倍数在之前的基础上再额外提供一个5，每个5^3的倍数再额外提供一个5....
int trailingZeroes(int n) {
    int count = 0;
    while (n) {
        count += n/5;
        n /= 5;
    }
    return count;
}

int main() {
    cout << trailingZeroes(10) << endl;
    return 0;
}
