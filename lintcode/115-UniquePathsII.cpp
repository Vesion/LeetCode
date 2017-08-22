#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) break;
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    return 0;
}
