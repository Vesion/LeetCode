#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : fast power
//      2^123 = 2^100 * 2^20 * 2^3
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        for (int n : b) {
            res = powx(res, 10) * powx(a, n) % 1337;
        }
        return res;
    }

    long long powx(long long x, long long n) {
        long long res = 1;
        while (n) {
            if (n&1) res = (res*x) % 1337;
            x = (x*x) % 1337;
            n >>= 1;
        }
        return res;
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
