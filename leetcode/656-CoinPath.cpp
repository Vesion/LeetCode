#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dp, naive, O(n^3) time, O(n^2) space
class Solution_1 {
public:
  vector<int> cheapestJump(vector<int>& A, int B) {
    int n = A.size();
    vector<vector<int>> res(n+1); res[1] = {1};
    vector<int> dp(n+1, INT_MAX); dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      if (A[i-1] == -1) continue;
      bool f = false;
      for (int j = i-1; j >= max(1, i-B); --j) {
        if (dp[j] != INT_MAX && A[j-1] != -1 && (dp[j]+A[j-1] < dp[i] || (dp[j]+A[j-1] == dp[i] && le(res[j], res[i])))) {
          res[i] = res[j];
          dp[i] = dp[j]+A[j-1];
          f = true;
        }
      }
      if (f) res[i].push_back(i);
    }
    return res[n];
  }

  bool le(vector<int>& a, vector<int>& b) {
    int an = a.size(), bn = b.size(), i = 0;
    for ( ; i < min(an, bn); ++i) if (a[i] != b[i]) return a[i] < b[i];
    return i == bn;
  }
};


// Solution 2 : dp, traverse from back to front, O(n^2) time, O(n) space
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
      if (A.empty() || A.back() == -1) return {};
      int n = A.size();
      vector<int> dp(n, INT_MAX), jump(n, -1);
      dp[n-1] = A[n-1];
      for (int i = n-2; i >= 0; --i) {
        if (A[i] == -1) continue;
        for (int j = i+1; j <= min(i+B, n-1); ++j) {
          if (dp[j] == INT_MAX) continue;
          if (A[i]+dp[j] < dp[i]) {
            dp[i] = A[i]+dp[j];
            jump[i] = j;
          }
        }
      }

      if (dp[0] == INT_MAX) return {};
      vector<int> res;
      int i = 0;
      while (i != -1) {
        res.push_back(i+1);
        i = jump[i];
      }
      return res;
    }
};


int main() {
  Solution s;
  vector<int> A = {0,-1,-1,-1,-1,-1};
  auto r = s.cheapestJump(A, 5);
  for (auto& e : r) cout << e << " "; cout << endl;
  return 0;
}
