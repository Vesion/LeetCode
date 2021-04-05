#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 546-RemoveBoxes

// Solution 1 : top-down + memo
class Solution {
public:
  int strangePrinter(string s) {
    if (s.empty()) return 0;
    s = removeDuplicates(s); // a small optimization
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return dfs(s, 0, n-1, dp);
  }

  int dfs(string& s, int l, int r, vector<vector<int>>& dp) {
    if (l > r) return 0;
    if (dp[l][r]) return dp[l][r];
    dp[l][r] = dfs(s, l, r-1, dp) + 1;
    for (int i = l; i < r; ++i) {
      if (s[i] == s[r]) {
        dp[l][r] = min(dp[l][r], dfs(s, l, i, dp)+dfs(s, i+1, r-1, dp));
      }
    }
    return dp[l][r];
  }

  string removeDuplicates(string& s) {
    string r;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (i == 0 || s[i] != s[i-1]) r += s[i];
    }
    return r;
  }
};


// Solution 2 : bottom-up dp
class Solution_2 {
public:
  int strangePrinter(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i+len-1 < n; ++i) {
        int j = i+len-1;
        if (i == j) dp[i][j] = 1;
        else {
          dp[i][j] = dp[i][j-1]+1;
          for (int k = i; k < j; ++k) if (s[k] == s[j]) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j-1]);
        }
      }
    }
    return dp[0][n-1];
  }
};


int main() {
  Solution_2 s;
  cout << s.strangePrinter("dddccbdbababaddcbcaabdbdddcccddbbaabddb") << endl;
  return 0;
}
