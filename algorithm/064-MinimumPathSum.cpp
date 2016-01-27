#include <iostream>
#include <vector>
using namespace std;

// dfs, TLE!!
int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x == 0 && y == 0)
        return grid[x][y];
    if (x < 0 || y < 0)
        return INT_MAX;
    return min(dfs(grid, x-1, y), dfs(grid, x, y-1)) + grid[x][y];
}
int minPathSum_dfs(vector<vector<int>>& grid) {
    return dfs(grid, grid.size()-1, grid[0].size()-1);
}

// dp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 2, 2, 2},
        {1, 2, 2, 2, 2},
        {1, 2, 2, 2, 2},
        {1, 1, 1, 1, 1},
    };
    cout << minPathSum_dfs(grid) << endl;
    cout << minPathSum(grid) << endl;
}
