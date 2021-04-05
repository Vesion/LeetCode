#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

// DP, similar to 516-LongestPalindromicSubsequence

// top-down
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/272297/DP-C%2B%2B-Clear-solution-explained
// dp[d][l][r] = the number of distinct palindromic subsequences in s[l...r] bordered by 'a'+d
class Solution {
public:
    const int kMod = 1e9+7;
    vector<vector<int>> dp[4];

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < 4; ++i) dp[i].resize(n, vector<int>(n, -1));
        for (int i = 0; i < 4; ++i) res = (res + dfs(s, 0, n-1, i)) % kMod;
        return res;
    }

    int dfs(const string& s, int l, int r, int d) {
        if (l > r) return 0;
        if (l == r) return s[l] == 'a'+d;
        if (dp[d][l][r] != -1) return dp[d][l][r];

        int res = 0;
        if (s[l] == s[r] && s[l] == 'a'+d) {
            res = 2;
            for (int i = 0; i < 4; ++i) res = (res + dfs(s, l+1, r-1, i)) % kMod;
        } else {
            res = (dfs(s, l+1, r, d) + dfs(s, l, r-1, d) - dfs(s, l+1, r-1, d)) % kMod;
            if (res < 0) res += kMod;
        }
        return dp[d][l][r] = res;
    }
};


// bottom-up
// https://discuss.leetcode.com/topic/111483/java-96ms-dp-solution-with-detailed-explanation
class Solution1 {
public:
  const int MOD = 1e9+7;

  int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i+len-1 < n; ++i) {
        int j = i+len-1;
        if (s[i] == s[j]) {
          int l = i+1, r = j-1;
          while (l <= r && s[l] != s[i]) ++l;
          while (l <= r && s[r] != s[j]) --r;
          if (l > r) dp[i][j] = dp[i+1][j-1]*2 + 2;
          else if (l == r) dp[i][j] = dp[i+1][j-1]*2 + 1;
          else dp[i][j] = dp[i+1][j-1]*2 - dp[l+1][r-1];
        } else {
          dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
        dp[i][j] = dp[i][j] < 0 ? dp[i][j]+MOD : dp[i][j]%MOD;
      }
    }
    return dp[0][n-1];
  }
};


int main() {
    return 0;
}
