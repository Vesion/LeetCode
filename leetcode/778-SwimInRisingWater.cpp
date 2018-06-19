#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 0 : union set, O(n^6)
class Solution_0 {
private:
  vector<int> root;
  int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
  }
  void unionSet(int i, int j) {
    int ri = findRoot(i), rj = findRoot(j);
    if (ri != rj) root[rj] = ri;
  }
  int go[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    root.resize(n*n);
    for (int i = 0; i < n*n; ++i) root[i] = i;
    int res = 0, target = n*n-1;
    while (true) { // n^2
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { // n^2
        if (findRoot(i*n+j) == findRoot(0) && res >= grid[i][j]) dfs(i, j, grid, n, res); // n^2
      }
      if (findRoot(0) == findRoot(target)) break;
      ++res;
    }
    return res;
  }

  void dfs(int i, int j, vector<vector<int>>& grid, int n, int t) {
    for (int d = 0; d < 4; ++d) {
      int ni = i+go[d][0], nj = j+go[d][1];
      int id = i*n+j, nid = ni*n+nj;
      if (ni >= 0 && ni < n && nj >= 0 && nj < n && findRoot(id) != findRoot(nid) && t >= grid[ni][nj]) {
        unionSet(id, nid);
        dfs(ni, nj, grid, n, t);
      }
    }
  }
};


// Solution 1 : union set, O(n^2)
class Solution {
private:
  vector<int> root;
  int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
  }
  void unionSet(int i, int j) {
    int ri = findRoot(i), rj = findRoot(j);
    if (ri != rj) root[rj] = ri;
  }
  int go[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    root.resize(n*n);
    for (int i = 0; i < n*n; ++i) root[i] = i;
    vector<pair<int,int>> g(n*n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
      g[grid[i][j]] = {i,j};

    int t = 0, target = n*n-1;
    while (t <= target) {
      int i = g[t].first, j = g[t].second;
      for (int d = 0; d < 4; ++d) {
        int ni = i+go[d][0], nj = j+go[d][1];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && t >= grid[ni][nj])
          unionSet(i*n+j, ni*n+nj);
      }
      if (findRoot(0) == findRoot(target)) break;
      ++t;
    }
    return t;
  }
};


// Solution 2 : heap, O(n^2logn)
class Solution_2 {
private:
  struct Node {
    int x, y, t;
    Node(int a, int b, int c) : x(a), y(b), t(c) {}
    bool operator< (const Node& rhs) const { return t > rhs.t; }
  };
  int go[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<Node> pq;
    vector<vector<int>> visit(n, vector<int>(n, 0));
    pq.push({0, 0, grid[0][0]});
    visit[0][0] = 1;

    int res = 0;
    while (!pq.empty()) {
      auto p = pq.top(); pq.pop();
      res = max(res, p.t);
      if (p.x == n-1 && p.y == n-1) break;
      for (int d = 0; d < 4; ++d) {
        int i = p.x+go[d][0], j = p.y+go[d][1];
          if (i >= 0 && i < n && j >= 0 && j < n && !visit[i][j]) {
            pq.push({i, j, grid[i][j]});
            visit[i][j] = 1;
          }
      }
    }
    return res;
  }
};


int main() {
  Solution_2 s;
  vector<vector<int>> g = {
    {10,12,4,6},{9,11,3,5},{1,7,13,8},{2,0,15,14}
  };
  cout << s.swimInWater(g) << endl;
  return 0;
}
