#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int res = 0;
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i+len-1< n; ++i) {
        int j = i+len-1;
        if (s[i] == s[j] && (i+1 >= j-1 || dp[i+1][j-1])) {
          ++res;
          dp[i][j] = true;
        }
      }
    }
    return res;
  }
};


int main() {
  return 0;
}
