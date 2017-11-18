#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DP, dp[i][j] = k, means S[i-k...i] is the shortest suffix substring of S, and T[0...j] is subsequece of it.
class Solution {
public:
  string minWindow(string S, string T) {
    int m = S.size(), n = T.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    for (int i = 0; i <= m; ++i) dp[i][0] = 0;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i-1][j] != INT_MAX) dp[i][j] = 1 + dp[i-1][j];
        if (S[i-1] == T[j-1] && dp[i-1][j-1] != INT_MAX) dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
      }
    }

    int j = -1, len = INT_MAX;
    for (int i = 0; i <= m; ++i) {
      if (dp[i][n] < len) {
        len = dp[i][n];
        j = i;
      }
    }
    return j < 0 ? "" : S.substr(j-len, len);
  }
};


int main() {
  Solution s;
  cout << s.minWindow("abcdebdde", "bde") << endl;
  return 0;
}
