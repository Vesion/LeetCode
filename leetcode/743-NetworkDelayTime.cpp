#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Shortest path in directed graph

// Solution 1 : Dijkstra
class Solution {
public:
  static const int MAXN = 105;
  int g[MAXN][MAXN];
  int has[MAXN], dist[MAXN];

  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) {
      if (i == j) g[i][j] = 0;
      g[i][j] = INT_MAX;
    }
    for (auto& p : times) g[p[0]][p[1]] = p[2];
    for (int i = 1; i <= N; ++i) {
      has[i] = false;
      dist[i] = INT_MAX;
    }

    dist[K] = 0;
    for (int i = 1; i <= N; ++i) {
      int d = INT_MAX, k;
      for (int j = 1; j <= N; ++j) {
        if (!has[j] && dist[j] < d) {
          d = dist[j];
          k = j;
        }
      }
      has[k] = true;
      for (int j = 1; j <= N; ++j) {
        if (!has[j] && g[k][j] != INT_MAX)
          dist[j] = min(dist[j], g[k][j]+dist[k]);
      }
    }

    int res = 0;
    for (int i = 1; i <= N; ++i) {
      if (!has[i]) return -1;
      res = max(res, dist[i]);
    }
    return res;
  }
};


// Solution 2 : SPFA
class Solution_2 {
public:
  static const int MAXN = 105;
  vector<pair<int,int>> g[MAXN];
  int has[MAXN], dist[MAXN];

  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    for (auto& p : times) g[p[0]].push_back({p[1], p[2]}) ; 
    for (int i = 1; i <= N; ++i) {
      has[i] = 0;
      dist[i] = INT_MAX;
    }

    queue<int> q;
    q.push(K);
    has[K] = true, dist[K] = 0;
    while (!q.empty()) {
      int i = q.front(); q.pop();
      has[i] = false;
      for (auto& p : g[i]) {
        int j = p.first, l = p.second;
        if (dist[j] > dist[i]+l) {
          dist[j] = dist[i]+l;
          if (!has[j]) {
            q.push(j);
            has[j] = true;
          }
        }
      }
    }

    int res = 0;
    for (int i = 1; i <= N; ++i) {
      if (dist[i] == INT_MAX) return -1;
      res = max(res, dist[i]);
    }
    return res;
  }
};


int main() {
  Solution_2 s;
  vector<vector<int>> t ={ { 2,1,1 },{ 2,3,1 },{ 3,4,1 } };
  cout << s.networkDelayTime(t, 4, 2) << endl;
  return 0;
}
