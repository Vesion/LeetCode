#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : trivial dp, O(n^2), TLE
class Solution_0 {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i) {
      dp[i] = dp[i-1];
      for (int j = 0; j < i; ++j) {
        dp[i] = max(dp[i], prices[i]-prices[j]-fee+dp[j]);
      }
    }
    return dp[n-1];
  }
};


// Solution 1 : optimized to O(n)
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> dp(n, 0);
    int maxt = INT_MIN;
    for (int i = 0; i < n; ++i) {
      if (i > 0) dp[i] = max(dp[i-1], prices[i]-fee+maxt);
      maxt = max(maxt, dp[i]-prices[i]);
    }
    return dp[n-1];
  }
};


int main() {
  Solution s;
  vector<int> p = { 1,3,7,5,10,3 };
  cout << s.maxProfit(p, 3) << endl;
  return 0;
}
