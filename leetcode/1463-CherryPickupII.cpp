#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Top-down, dp, O(m*n*n)
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(n, 0)));
        return dfs(grid, 0, 0, n-1);
    }

    int dfs(const vector<vector<int>>& grid, int row, int c1, int c2) {
        if (row >= m) return 0;
        if (c1 > c2) return dfs(grid, row, c2, c1);
        if (dp[row][c1][c2]) return dp[row][c1][c2];
        int c = 0;
        for (int d1 = -1; d1 <= 1; ++d1) {
            const int nc1 = c1 + d1;
            if (nc1 < 0 || nc1 >= n) continue;
            for (int d2 = -1; d2 <= 1; ++d2) {
                const int nc2 = c2 + d2;
                if (nc2 < 0 || nc2 >= n) continue;
                c = max(c, dfs(grid, row+1, nc1, nc2));
            }
        }
        c += grid[row][c1];
        if (c1 != c2) c += grid[row][c2];
        dp[row][c1][c2] = c;
        return c;
    }
};

// Bottom-up, dp, O(m*n*n)
class Solution1 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int i = m-1; i >= 0; --i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int c = 0;
                    for (int d1 = -1; d1 <= 1; ++d1) {
                        const int nj1 = j1 + d1;
                        if (nj1 < 0 || nj1 >= n) continue;
                        for (int d2 = -1; d2 <= 1; ++d2) {
                            const int nj2 = j2 + d2;
                            if (nj2 < 0 || nj2 >= n) continue;
                            if (i < m-1) c = max(c, dp[i+1][nj1][nj2]);
                        }
                    }
                    c += grid[i][j1];
                    if (j1 != j2) c += grid[i][j2];
                    dp[i][j1][j2] = c;
                }
            }
        }
        return dp[0][0][n-1];
    }
};

int main() {
    return 0;
}
