#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class Solution {
public:
  int m, n;
  vector<vector<bool>> f;
  int go[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

  int numDistinctIslands(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    m = grid.size(), n = grid[0].size();
    f.resize(m, vector<bool>(n, false));
    set<vector<pair<int,int>>> dict;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      if (grid[i][j] && !f[i][j]) {
        vector<pair<int,int>> island;
        dfs(grid, i, j, i, j, island);
        dict.insert(island);
      }
    }
    return dict.size();
  }

  void dfs(vector<vector<int>>& grid, int i, int j, int offsetX, int offsetY, vector<pair<int,int>>& island) {
    f[i][j] = true;
    island.push_back({i-offsetX, j-offsetY});
    for (int d = 0; d < 4; ++d) {
      int ni = i+go[d][0], nj = j+go[d][1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n || !grid[ni][nj] || f[ni][nj]) continue;
      dfs(grid, ni, nj, offsetX, offsetY, island);
    }
  }
};


int main() {
  Solution s;
  vector<vector<int>> g = { { 1,1,1,1 },{ 1,0,1,0 },{ 0,0,0,0 },{ 0,1,1,1 },{ 1,1,0,1 } };
  cout << s.numDistinctIslands(g) << endl;
  return 0;
}
