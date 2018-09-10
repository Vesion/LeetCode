#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem:
//      Given two numbers R and N, how many numbers in range [1, R] are co-prime with N?
//
// Solution:
//      The brute-force solution is checking numbers in [1, R] one by one.
//      Using inclusion-exclusion-principle, we can calculate how many numbers in [1, R] are NOT co-prime with N (i.e. can be divided by some prime-factor of N)
//      then result is N - (count we get above)

int getCoPrimes(int r, int n) {
    // step 1 : get all prime factors of n
    vector<int> p;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            p.push_back(i);
            while (n%i == 0) n /= i;
        }
    }
    if (n > 1) p.push_back(n);

    // step 2 : calculate how many numbers in [1, R] are not co-prime with N
    int res = 0;
    for (int used = 1; used < (1<<p.size()); ++used) {
        int c = 0, mul = 1;  
        for (int i = 0; i < (int)p.size(); ++i) {
            if (used & (1<<i)) {
                ++c;
                mul *= p[i];
            }
        }
        if (c&1) res += r / mul;
        else res -= r / mul;
    }
    return r-res;
}


int main() {
    for (int i = 1; i <= 100; ++i) cout << getCoPrimes(i, i) << endl;
    return 0;
}
