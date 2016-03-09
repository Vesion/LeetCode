#include <iostream>
using namespace std;

// Solution 1 : brute-force, iterate all numbers, O(n), TLE of course
int rangeBitwiseAnd_bf(int m, int n) {
    int result = m;
    for (int k = m+1; k <= n; ++k)
        result &= k;
    return result;
}


// Solution 2 : O(1)
// Consider the bits from low to high. if n > m, the lowest bit will be 0, and then we could transfer the problem to sub-problem: rangeBitwiseAnd(m>>1, n>>1).
int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? rangeBitwiseAnd(m>>1, n>>1)<<1 : m;
}

int main() {
    cout << rangeBitwiseAnd_bf(4, 7) << endl;
    cout << rangeBitwiseAnd(4, 7) << endl;
    return 0;
}
