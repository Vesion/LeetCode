#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Given an integer n, count the total number of digit K appearing in range [1, n]
//
// K = 1
// https://leetcode.com/problems/number-of-digit-one/
//
// K = 2
// CC150 Page 334

// A template which can solve general 'count digit k' problems
// O(d), d is the digit length of n
class Solution {
public:
    using ll = long long; // be careful with overflow

    int countDigitKs(int n, int k) {
        int res = 0;
        int len = to_string(n).size();
        for (int d = 0; d < len; ++d) res += helper(n, d, k);
        return res;
    }

    // count number of ks on digit d
    int helper(int n, int d, int k) {
        ll base = pow(10, d);
        int digit = (n / base) % 10;
        ll t = n / (base * 10); // 43210, 2 -> 43

        if (digit < k) return t * base; // round down
        else if (digit == k) return t * base + n%base + 1; // round down + mod part
        else return (t + 1) * base; // round up
    }
};


int main() {
    Solution s;
    cout << s.countDigitKs(543210, 2) << endl;
    return 0;
}
