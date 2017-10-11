#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Unbound Knapsack + Compression DP
class Solution {
public:
  int minStickers(vector<string>& stickers, string target) {
    int n = target.size();
    int N = 1 << n;
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
      if (dp[i] == INT_MAX) continue;
      for (string& s : stickers) {
        int ni = i;
        for (char& c : s) {
          for (int j = 0; j < n; ++j) {
            if (target[j] == c && !((ni >> j) & 1)) {
              ni |= (1 << j);
              break;
            }
          }
        }
        dp[ni] = min(dp[ni], dp[i]+1);
      }
    }
    return dp[N-1] == INT_MAX ? -1 : dp[N-1];
  }
};


int main() {
  return 0;
}
