#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Description : Count the number of prime numbers less than a non-negative number, n.

// Solution 1 : brute-force, O(n^2) time, TLE
int countPrimes_bf(int n) {
    if (n < 3) return 0;
    int count = 0;
    for (int i = 2; i < n; ++i) {
        bool is = true;
        for (int j = 2; j <= int(sqrt(i)); ++j) {
            if (i%j == 0) { is = false; break; }
        }
        if (is) ++count;
    }
    return count;
}


// Solution 2 : Sieve of Eratosthenes algorithm
// refer to https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// use a table to record all composite number
int countPrimes_SoE(int n) {
    if (n < 3) return 0;
    vector<bool> v(n, false);
    int count = 1;
    int upper = sqrt(n);
    for (int i = 3; i < n; i+=2) {
        if (v[i]) continue;
        ++count;
        if (i > upper) continue; // in case of overflow
        for (int j = i*i; j < n; j += i)
            v[j] = true;
    }
    return count;
}


// Solution 2 v2 : use some tricks to be much much FASTER!!
int countPrimes_SoE_v2(int n) {
    if (n < 3) return 0;
    int count = n>>1; // prime numbers must not be even numbers(except 2), initialize count to n/2, removes all even number(not 2) and 1
    int m = sqrt(n-1); // upper
    bool *table = new bool[n]; // use new bool array, rather than std::vector
    for (int i = 3; i <= m; i += 2) { // only traverse odd numbers
        if (!table[i]) {
            for (int step = i<<1, j = i*i; j < n; j += step) // step is i*2, ignore even numbers
                if (!table[j]) {
                    table[j] = true;
                    --count;
                }
        }
    }
    return count;
}

int main() {
    cout << countPrimes_bf(10) << endl;
    cout << countPrimes_SoE(10) << endl;
    cout << countPrimes_SoE_v2(10) << endl;
    return 0;
}
