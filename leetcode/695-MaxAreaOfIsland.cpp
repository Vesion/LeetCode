#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int go[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  int m, n;
  vector<vector<bool>> f;

  int maxAreaOfIsland(vector<vector<int>>& grid) { 
    if (grid.empty()) return 0;
    m = grid.size(), n = grid[0].size();
    f.resize(m, vector<bool>(n, false));
    int res = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      if (grid[i][j] && !f[i][j]) res = max(res, dfs(grid, i, j));
    }
    return res;
  }

  int dfs(vector<vector<int>>& grid, int i, int j) {
    f[i][j] = true;
    int area = 1;
    for (int d = 0; d < 4; ++d) {
      int ni = i+go[d][0], nj = j+go[d][1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n || !grid[ni][nj] || f[ni][nj]) continue;
      area += dfs(grid, ni, nj);
    }
    return area;
  }
};


int main() {
  return 0;
}
