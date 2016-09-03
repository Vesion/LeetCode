#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial
class Solution {
public:
    int mod = 1337;

    long long powm(long long x, long long n) {
        long long r = 1, t = x;
        while (n) {
            if (n & 1) r = (r * t) % mod;
            t = (t * t) % mod;
            n >>= 1;
        }
        return r % mod;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return a % mod;
        long long r = 1;
        for (int &n : b)
            r = powm(r, 10) * powm(a, n) % mod;
        return r;
    }
};


// Solution 2 : Math solution based on Euler's theorem
// https://discuss.leetcode.com/topic/50586/math-solusion-based-on-euler-s-theorem-power-called-only-once-c-java-1-line-python/3
class Solution_m {
public:
    int superPow(int a, vector<int>& b) {
        if (a % 1337 == 0) return 0; // this line could also be removed
        int p = 0;
        for (int i : b) p = (p * 10 + i) % 1140;
        if (p == 0) p += 1140;
        return power(a, p, 1337);
    }
    int power(int x, int n, int mod) {
        int ret = 1;
        for (x %= mod; n; x = x * x % mod, n >>= 1) if (n & 1) ret = ret * x % mod;
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> b = {2, 0, 0};
    cout << s.superPow(INT_MAX, b) << endl;
    return 0;
}
