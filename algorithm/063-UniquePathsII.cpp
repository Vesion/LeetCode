#include <iostream>
#include <vector>
using namespace std;

// dfs, TLE!!
int dfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
    if (i == n-1 && j == m-1)
        return 1;
    if (i == n || j == m || grid[j][i] == 1)
        return 0;
    return dfs(i+1, j, grid, m, n) + dfs(i, j+1, grid, m, n);
}
int uniquePathsWithObstacles_dfs(vector<vector<int>>& obstacleGrid) {
    return dfs(0, 0, obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size());
}


// dp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
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
            dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : (dp[i-1][j] + dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    cout << uniquePathsWithObstacles_dfs(grid) << endl;
    cout << uniquePathsWithObstacles(grid) << endl;
    return 0;
}
