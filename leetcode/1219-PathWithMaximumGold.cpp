#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DFS
class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j]) res = max(res, dfs(grid, i, j));
        }
        return res;
    }

    int dfs(const vector<vector<int>>& grid, int i, int j) {
        vis[i][j] = true;
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        int res = 0;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d], nj = j+go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (grid[ni][nj] == 0 || vis[ni][nj]) continue;
            res = max(res, dfs(grid, ni, nj));
        }
        vis[i][j] = false;
        return res + grid[i][j];
    }
};

int main() {

}
