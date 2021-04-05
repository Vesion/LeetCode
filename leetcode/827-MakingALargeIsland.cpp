#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int m, n;
    unordered_map<int,int> area;
    int id;
    const int go[5] = {1, 0, -1, 0, 1};

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        id = 2;
        int res = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                area[id] = dfs(grid, i, j);
                ++id;
            }
        }
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                int a = 1;
                unordered_set<int> s;
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    int id = grid[ni][nj];
                    if (id > 1 && !s.count(id)) {
                        a += area[id];
                        s.insert(id);
                    }
                }
                res = max(res, a);
            } else {
                res = max(res, area[grid[i][j]]);
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        int res = 1;
        grid[i][j] = id;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d], nj = j+go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != 1) continue;
            res += dfs(grid, ni, nj);
        }
        return res;
    }
};

int main() {

}