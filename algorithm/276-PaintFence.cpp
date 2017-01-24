#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, need two states, painting this the same color with previous one or not:
//      dp[i][0] means the solution for painting i the same color with (i-1)'s
//      dp[i][1] means the solution for painting i the different color with (i-1)'s
// so
//      dp[i][0] = dp[i-1][1]                      // no more than two fences have same color
//      dp[i][1] = (dp[i-1][0]+dp[i-1][1]) * (k-1) // cannot pick the same color with previous one's
//
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = k;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0]+dp[i-1][1]) * (k-1);
        }
        return dp[n-1][0] + dp[n-1][1];
    }
};


int main() {
    return 0;
}
