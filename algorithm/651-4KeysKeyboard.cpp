#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : straightforward dp, O(n^2)
class Solution {
public:
  int maxA(int N) {
    vector<int> dp(N+1, 0);
    for (int i = 1; i <= N; ++i) {
      dp[i] = i;
      for (int j = 1; j+3 <= i; ++j) {
        dp[i] = max(dp[i], dp[j]*(i-j-1));
      }
    }
    return dp[N];
  }
};


// Solution 2 : math dp, O(n)
class Solution_2 {
public:
  int maxA(int N) {
    if (N <= 6) return N;
    vector<int> dp(N+1, 0);
    for (int i = 1; i <= 6; i++) dp[i] = i;
    for (int i = 7; i <= N; ++i) {
      dp[i] = max(dp[i-4]*3, dp[i-5]*4);
    }
    return dp[N];
  }
};


int main() {
  return 0;
}
