#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// not that easy
//      dp[i][0] means number of painting ways which i's color is same with (i-1)'s color
//      dp[i][1] means number of painting ways which i's color is different with (i-1)' color
// so
//      dp[i][0] = dp[i-1][1]
//      dp[i][1] = (dp[i-1][0]+dp[i-1][1]) * (k-1)
//
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[1][0] = k;
        dp[1][1] = k*(k-1);
        for (int i = 2; i < n; ++i) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) * (k-1);
        }
        return dp[n-1][0] + dp[n-1][1];
    }
};

int main() {
    Solution s;
    return 0;
}
