#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

// The challenge is how to hash an island.
//
// https://discuss.leetcode.com/topic/107407/accepted-dfs-c-solution
//
class Solution {
public:
  int numDistinctIslands2(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();

    unordered_set<int> islands;
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (grid[r][c]) {
          vector<pair<int, int>> pts;
          dfs(grid, m, n, r, c, pts);
          int hash = compute_hash(pts);
          islands.insert(hash);
        }
      }
    }

    return islands.size();
  }

private:
  int compute_hash(vector<pair<int, int>>& pts) {
    int n = pts.size();
    int hash = 0;
    int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
    for (int i = 0; i < n; ++i) {
      const auto& pt1 = pts[i];
      xmin = std::min(xmin, pt1.first);
      ymin = std::min(ymin, pt1.second);
      xmax = std::max(xmax, pt1.first);
      ymax = std::max(ymax, pt1.second);
      for (int j = i + 1; j < n; ++j) {
        const auto& pt2 = pts[j];
        int delta_x = pt1.first - pt2.first;
        int delta_y = pt1.second - pt2.second;
        if (delta_x == 0 || delta_y == 0) {
          hash += 19 * (delta_x * delta_x + delta_y * delta_y);
        } else {
          hash += 31 * (delta_x * delta_x + delta_y * delta_y);
        }

      }
    }


    int delta_x = xmax - xmin, delta_y = ymax - ymin;
    hash += 193 * (delta_x * delta_x + delta_y * delta_y) + 97 * delta_x * delta_y;
    return hash;
  }

  int compute_hash_improved(vector<pair<int, int>>& pts) {
    int n = pts.size();
    int hash = 0;
    unordered_map<int, int> stats1, stats2;

    for (int i = 0; i < n; ++i) {
      const auto& pt1 = pts[i];
      stats1[pt1.first]++;
      stats2[pt1.second]++;
      for (int j = i + 1; j < n; ++j) {
        const auto& pt2 = pts[j];
        int delta_x = pt1.first - pt2.first;
        int delta_y = pt1.second - pt2.second;
        if (delta_x == 0 || delta_y == 0) {
          hash += 19 * (delta_x * delta_x + delta_y * delta_y);
        } else {
          hash += 31 * (delta_x * delta_x + delta_y * delta_y);
        } 
      }
    }

    for (auto& kv : stats1) {
      hash += 73 * kv.second * kv.second;
    }
    for (auto& kv : stats2) {
      hash += 73 * kv.second * kv.second;
    }

    int delta_x = stats1.size(), delta_y = stats2.size();
    hash += 193 * (delta_x * delta_x + delta_y * delta_y) + 97 * delta_x * delta_y;
    return hash;
  }

  void dfs(vector<vector<int>>& grid, int m, int n, int r, int c, vector<pair<int, int>>& pts) {
    bool outOfBound = (r < 0 || r >= m || c < 0 || c >= n);
    if (outOfBound || grid[r][c] == 0) return;

    grid[r][c] = 0;
    pts.emplace_back(r, c);
    dfs(grid, m, n, r - 1, c, pts);
    dfs(grid, m, n, r + 1, c, pts);
    dfs(grid, m, n, r, c - 1, pts);
    dfs(grid, m, n, r, c + 1, pts);
  }    
};


int main() {
  return 0;
}
