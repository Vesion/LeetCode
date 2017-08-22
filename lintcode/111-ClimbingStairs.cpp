#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : recursively
class Solution_1 {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};


// Solution 2 : iteratively
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(n+1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2]; 
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}
