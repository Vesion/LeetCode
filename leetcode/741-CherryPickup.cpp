#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : Wrong! two pass dp, record path in the first dp, clear path then do the second dp

// Solution 1 : Two threads dp
//    dp[i1][j1][i2][j2] means the max value when the first thread at {i1,j1}, the second thread at {i2,j2}
//    so it's O(n^4), but we can let the two threads go simutaneously
//    dp[k][i1][i2] means at {i1, k-i1} and {i2, k-i2}, and decrease the time to O(n^3)
//
// http://blog.csdn.net/u011077606/article/details/43302987
//
class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int N = n-1+n-1;
    dp[0][0] = grid[0][0];
    for (int k = 1; k <= N; ++k) {
      for (int i1 = n-1; i1 >= 0; --i1) { // from bottom to up, reuse old states
        for (int i2 = i1; i2 >= 0; --i2) {
          int j1 = k-i1, j2 = k-i2;
          if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) continue;
          if (grid[i1][j1] < 0 || grid[i2][j2] < 0) { dp[i1][i2] = -1; continue; }
          int add = grid[i1][j1] + (i1 != i2 ? grid[i2][j2] : 0);
          int best = -1;
          if (i1 > 0 && i2 > 0 && dp[i1-1][i2-1] >= 0) best = max(best, dp[i1-1][i2-1]+add); // up up
          if (i1 > 0 && j2 > 0 && dp[i1-1][i2] >= 0) best = max(best, dp[i1-1][i2]+add); // up left
          if (j1 > 0 && i2 > 0 && dp[i1][i2-1] >= 0) best = max(best, dp[i1][i2-1]+add); // left up
          if (j1 > 0 && j2 > 0 && dp[i1][i2] >= 0) best = max(best, dp[i1][i2]+add); // left left
          dp[i1][i2] = best;
        }
      }
    }
    return dp[n-1][n-1] < 0 ? 0 : dp[n-1][n-1];
  }
};


int main() {
  Solution s;
  vector<vector<int>> g = { { 1,1,1,1,0,0,0 },{ 0,0,0,1,0,0,0 },{ 0,0,0,1,0,0,1 },{ 1,0,0,1,0,0,0 },{ 0,0,0,1,0,0,0 },{ 0,0,0,1,0,0,0 },{ 0,0,0,1,1,1,1 } };
  cout << s.cherryPickup(g) << endl;
  return 0;
}
