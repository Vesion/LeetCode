#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// DP, similar to 516-LongestPalindromicSubsequence

// Solution 1 : dp, O(n^2)
// https://discuss.leetcode.com/topic/111241/c-o-n-2-time-o-n-memory-with-explanation
class Solution {
public:
  const int MOD = 1e9+7;
  int countPalindromicSubsequences(string s) {
    int n = s.size();
    int dp[3][n][26];
    for (int len = 1; len <=n; ++len) {
      for (int i = 0; i + len <=n; ++i) for (int x = 0; x < 26; ++x)  {
        int &ans = dp[2][i][x];
        ans = 0;
        int j = i + len - 1;
        char c = 'a' + x;
        if (len == 1) ans = s[i] == c;
        else {
          if (s[i] != c) ans = dp[1][i+1][x];
          else if (s[j] != c) ans = dp[1][i][x];
          else {
            ans = 2;
            if (len > 2) for (int y = 0; y < 26;++y) {
              ans += dp[0][i+1][y];
              ans %=MOD;
            }
          }
        }
      }
      for (int i=0;i<2;++i) for (int j = 0; j < n; ++j) for (int x=0; x < 26;++x)
        dp[i][j][x] = dp[i+1][j][x];
    }
    int ret = 0;
    for (int x = 0; x < 26;++x) ret = (ret + dp[2][0][x]) %MOD;
    return ret;
  }
};


// Soluton 2 : top-down + memo, O(n*n*logn)
// https://discuss.leetcode.com/topic/111230/accepted-java-solution-using-memoization
class Solution_2 {
public:
  const int MOD = 1e9+7;

  int countPalindromicSubsequences(string s) {
    vector<set<int>> ids(26);
    int n = s.size();
    for (int i = 0; i < n; ++i) ids[s[i]-'a'].insert(i);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return dfs(s, ids, dp, 0, n);
  }

  int dfs(string& s, vector<set<int>>& ids, vector<vector<int>>& dp, int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    long long res = 0;
    for (int i = 0; i < 26; ++i) {
      auto lit = ids[i].lower_bound(l);
      auto rit = ids[i].lower_bound(r);
      if (rit == ids[i].begin() || lit == ids[i].end() || *lit >= r) continue;
      --rit;
      ++res;
      if (*lit != *rit) ++res;
      res += dfs(s, ids, dp, (*lit)+1, *rit);
    }
    dp[l][r] = res % MOD;
    return dp[l][r];
  }
};


// Solution 3 : dp, O(n^3)
// https://discuss.leetcode.com/topic/111483/java-96ms-dp-solution-with-detailed-explanation
class Solution_3 {
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
  Solution s;
  cout << s.countPalindromicSubsequences("bccb") << endl;
  cout << s.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << endl;
  return 0;
}
