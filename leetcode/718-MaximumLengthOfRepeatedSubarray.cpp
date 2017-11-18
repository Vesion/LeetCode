#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Same with Longest Common Substring
class Solution {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    int res= 0;
    int na = A.size(), nb = B.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, 0));
    for (int i = 1; i <= na; ++i) {
      for (int j = 1; j <= nb; ++j) {
        if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = 0;
        res = max(res, dp[i][j]);
      }
    }
    return res;
  }
};


int main() {
  return 0;
}
