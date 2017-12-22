#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
  static const int MAXN = 51;
  int m, n;
  int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  int v[MAXN][MAXN], f[MAXN][MAXN];

  int containVirus(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    int res = 0;
    while (true) {
      memset(v, 0, sizeof v);
      int max_a = 0, max_i, max_j, max_w;
      for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1 && !v[i][j]) {
          int w = 0, a = 0;
          findMax(grid, i, j, w, a);
          if (a > max_a) max_a = a, max_i = i, max_j = j, max_w = w;
        }
      }
      if (max_a == 0) break;
      res += max_w;
      memset(v, 0, sizeof v);
      fill(grid, max_i, max_j);
      memset(f, 0, sizeof f);
      infect(grid);
    }
    return res;
  }

  // find the the affected area that threatens the most uninfected cells
  void findMax(vector<vector<int>>& grid, int row, int col, int& w, int& a) {
    memset(f, 0, sizeof f);
    queue<pair<int,int>> q;
    q.push({row, col}); v[row][col] = 1;
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second; q.pop();
      for (int d = 0; d < 4; ++d) {
        int ni = i+go[d][0], nj = j+go[d][1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
        else if (grid[ni][nj] == 0 && !f[ni][nj]) { ++a; f[ni][nj] = 1; }
        if (grid[ni][nj] == 1 && !v[ni][nj]) { q.push({ni,nj}); v[ni][nj] = 1; }
        if (grid[ni][nj] == 0) ++w;
      }
    }
  }

  // fill the affected area to 2
  void fill(vector<vector<int>>& grid, int row, int col) {
    queue<pair<int,int>> q;
    q.push({row, col}); v[row][col] = 1;
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second; q.pop();
      grid[i][j] = 2;
      for (int d = 0; d < 4; ++d) {
        int ni = i+go[d][0], nj = j+go[d][1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
        if (grid[ni][nj] == 1 && !v[ni][nj]) { q.push({ni,nj}); v[ni][nj] = 1; }
      }
    }
  }

  // other areas begin to infect
  void infect(vector<vector<int>>& grid) {
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1 && !v[i][j]) {
        queue<pair<int,int>> q;
        q.push({i,j}); v[i][j] = 1;
        while (!q.empty()) {
          int x = q.front().first, y = q.front().second; q.pop();
          for (int d = 0; d < 4; ++d) {
            int ni = x+go[d][0], nj = y+go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (grid[ni][nj] == 0 && !f[ni][nj]) f[ni][nj] = 1;
            if (grid[ni][nj] == 1 && !v[ni][nj]) { q.push({ni,nj}); v[ni][nj] = 1; }
          }
        }
      }
    }
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
      if (f[i][j]) grid[i][j] = 1;
  }
};


int main() {
  Solution s;
  vector<vector<int>> g = 
{ { 1,1,1,0,0,0,0,0,0 },
  { 1,0,1,0,1,1,1,1,1 },
  { 1,1,1,0,0,0,0,0,0 } };
  cout << s.containVirus(g) << endl;
  return 0;
}
