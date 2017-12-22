#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1, 0);
    for (int i = 2; i <= n; ++i) {
      dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    }
    return dp[n];
  }
};


int main() {
  Solution s;
  vector<int> c({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
  cout << s.minCostClimbingStairs(c) << endl;
  return 0;
}
