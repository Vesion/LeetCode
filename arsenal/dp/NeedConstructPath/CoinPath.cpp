#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/coin-path/
//
// dp, traverse from back to front, O(n^2) time, O(n) space
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
      if (A.empty() || A.back() == -1) return {};
      int n = A.size();
      vector<int> dp(n, INT_MAX), pre(n, -1);
      dp[n-1] = A[n-1];
      for (int i = n-2; i >= 0; --i) {
        if (A[i] == -1) continue;
        for (int j = i+1; j <= min(i+B, n-1); ++j) {
          if (dp[j] == INT_MAX) continue;
          if (A[i]+dp[j] < dp[i]) {
            dp[i] = A[i]+dp[j];
            pre[i] = j;
          }
        }
      }

      if (dp[0] == INT_MAX) return {};
      vector<int> res;
      int i = 0;
      while (i != -1) {
        res.push_back(i+1);
        i = pre[i];
      }
      return res;
    }
};


int main() {
  return 0;
}
