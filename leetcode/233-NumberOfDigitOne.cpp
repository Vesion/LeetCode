#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : count 1s on every digit
// a template which can solve general 'count digit k' problem

class Solution {
public:
    using ll = long long; // be careful with overflow

    int countDigitOne(int n) {
        int res = 0;
        int len = to_string(n).size();
        for (int d = 0; d < len; ++d) res += helper(n, d, 1);
        return res;
    }

    // count number of ks on digit d
    int helper(int n, int d, int k) {
        ll base = pow(10, d);
        int digit = (n / base) % 10;

        ll t = n / (base * 10); // 43210, 3 -> 43
        if (digit < k) return t * base;
        else if (digit == k) return t * base + n%base + 1;
        else return (t + 1) * base;
    }
};


// Solution 2 : more concise
// https://discuss.leetcode.com/topic/18054/4-lines-o-log-n-c-java-python
class Solution_2 {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long r = n / i, m = n % i;
            res += (r+8)/10*i + (r%10 == 1 ? m+1 : 0);
        }
        return res;
    }
};


int main() {
    return 0;
}
