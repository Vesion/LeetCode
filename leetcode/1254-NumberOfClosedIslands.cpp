#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int m, n;
    const int go[5] = {1, 0, -1, 0, 1};

    // Should use bool& to get result rather than return a boolean,
    // because we want to traverse all reachable cells per dfs.
    void dfs(vector<vector<int>>& grid, int i, int j, bool& closed) {
        for (int d = 0; d < 4; ++d) {
            int ni = i + go[d], nj = j + go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                closed = false;
                continue;
            }
            if (grid[ni][nj] != 0) continue;
            grid[ni][nj] = 2;
            dfs(grid, ni, nj, closed);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int s = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                grid[i][j] = 2;
                bool closed = true;
                dfs(grid, i, j, closed);
                if (closed) ++s;
            }
        }
        return s;
    }
};

int main() {
    vector<vector<int>> f = {
    {0,0,1,1,0,1,0,0,1,0},
    {1,1,0,1,1,0,1,1,1,0},
    {1,0,1,1,1,0,0,1,1,0},
    {0,1,1,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,1,1,1,0},
    {0,1,0,1,0,1,0,1,1,1},
    {1,0,1,0,1,1,0,0,0,1},
    {1,1,1,1,1,1,0,0,0,0},
    {1,1,1,0,0,1,0,1,0,1},
    {1,1,1,0,1,1,0,1,1,0}
    };
    Solution s;
    cout << s.closedIsland(f) << endl;
}