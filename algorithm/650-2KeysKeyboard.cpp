#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int minSteps(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = dp[1] = 0;
    for (int i = 1; i <= n/2; ++i) {
      for (int k = 2; i*k <= n; ++k) {
        int j = i*k;
        dp[j] = min(dp[j], dp[i]+k);
      }
    }
    return dp[n];
  }
};


int main() {
  Solution s;
  cout << s.minSteps(1024) << endl;
  return 0;
}
