#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j1 = 0; j1 < n; ++j1) if (grid[i][j1])
        for (int j2 = j1+1; j2 < n; ++j2) if (grid[i][j2]) {
          res += dp[j1][j2];
          ++dp[j1][j2];
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<int>> g = {
    {1,1,1},
    {1,1,1},
    {1,1,1},
  };
  cout << s.countCornerRectangles(g) << endl;
  return 0;
}
