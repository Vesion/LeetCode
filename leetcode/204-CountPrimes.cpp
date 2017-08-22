#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : Sieve of Eratosthenes 埃式筛法
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i*i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i+i; j < n; j += i)
                    isPrime[j] = false;
            }
        }
        int res = 0;
        for (int i = 2; i < n; ++i) res += isPrime[i];
        return res;
    }
};

// Sieve of Euler 欧拉筛法 
class Solution_2 {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isPrime(n, true);
        vector<int> prime(n, 0);
        int c = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) prime[c++] = i;
            for (int j = 0; j < c; ++j) {
                int t = i * prime[j];
                if (t >= n) break;
                isPrime[t] = false;
                if (i % prime[j] == 0) break;
            }
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(6) << endl;
    return 0;
}

