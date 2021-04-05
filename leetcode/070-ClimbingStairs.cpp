#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// It's fibonacci
// Solution 1 : O(n) time O(n) space
class Solution1 {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; ++i) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};


// Solution 2 : O(n) time, O(1) space
class Solution {
public:
    int climbStairs(int n) {
        int pre = 1, cur = 1;
        while (n--) {
            cur += pre;
            pre = cur - pre;
        }
        return pre;
    }
};


int main() {
    return 0;
}
