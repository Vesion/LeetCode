#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  using ll = long long;
  const int MOD = 1e9+7;

  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int n = s.size();
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '*' ? 9 : 1;
    for (int i = 2; i <= n; ++i) {
      if (s[i-1] == '*') {
        if (s[i-2] == '*') {
          dp[i] = (dp[i-1] * 9 + dp[i-2] * 15) % MOD;
        } else {
          dp[i] = (dp[i-1] * 9) % MOD;
          if (s[i-2] == '1') dp[i] = (dp[i] + dp[i-2] * 9) % MOD;
          if (s[i-2] == '2') dp[i] = (dp[i] + dp[i-2] * 6) % MOD;
        }
      } else {
        if (s[i-2] == '*') {
          if (s[i-1] == '0') {
            dp[i] = (dp[i-2] * 2) % MOD;
          } else {
            dp[i] = dp[i-1];
            if (isValid(1, s[i-1]-'0')) dp[i] = (dp[i] + dp[i-2]) % MOD;
            if (isValid(2, s[i-1]-'0')) dp[i] = (dp[i] + dp[i-2]) % MOD;
          }
        } else {
          if (s[i-1] == '0') {
            if (isValid(s[i-2]-'0', 0)) dp[i] = dp[i-2];
            else dp[i] = 0;
          } else {
            dp[i] = dp[i-1];
            if (isValid(s[i-2]-'0', s[i-1]-'0')) dp[i] = (dp[i] + dp[i-2]) % MOD;
          }
        }
      }
    }
    return dp[n];
  }

  bool isValid(int i, int j) {
    if (i == 0) return false;
    int v = i*10 + j;
    return v >= 1 && v <= 26;
  }
};


int main() {
  Solution s;
  cout << s.numDecodings("0") << endl;
  return 0;
}
