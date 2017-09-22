#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
  int m, n;
  int go[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
  vector<vector<int>> visited;

  int bfs(int i1, int j1, int i2, int j2, vector<vector<int>>& forest) {
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) visited[i][j] = false;
    queue<pair<int,int>> q;
    q.push({i1, j1});
    visited[i1][j1] = true;
    int steps = 0;
    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        int i = q.front().first, j = q.front().second; q.pop();
        if (i == i2 && j == j2) return steps;
        for (int d = 0; d < 4; ++d) {
          int ni = i+go[d][0], nj = j+go[d][1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n || forest[ni][nj] == 0 || visited[ni][nj]) continue;
          q.push({ni, nj});
          visited[ni][nj] = true;
        }
      }
      ++steps;
    }
    return -1;
  }

  int cutOffTree(vector<vector<int>>& forest) {
    if (forest.empty()) return 0;
    m = forest.size(), n = forest[0].size();
    visited.resize(m, vector<int>(n, false));
    vector<pair<int,int>> ps;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      if (forest[i][j] > 1) ps.push_back({i, j});
    }
    sort(ps.begin(), ps.end(), [&forest](const pair<int,int>&p1, const pair<int,int>& p2) { return forest[p1.first][p1.second] < forest[p2.first][p2.second]; });
    int res = 0;
    int i = 0, j = 0;
    for (auto& p : ps) {
      int r = bfs(i, j, p.first, p.second, forest);
      if (r == -1) return -1;
      res += r;
      i = p.first, j = p.second;
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<int>> f = {
    { 1,2,3 },
    { 0,0,0 },
    { 7,6,5 }
  };
  cout << s.cutOffTree(f) << endl;
  return 0;
}
