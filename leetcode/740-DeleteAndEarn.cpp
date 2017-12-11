#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 198-HouseRobber
// DP
class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    const int N = 10000;
    vector<int> a(N+1, 0);
    for (int& num : nums) a[num] += num;
    vector<vector<int>> dp(N+1, vector<int>(2, 0));
    for (int i = 1; i <= N; ++i) {
      dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
      dp[i][1] = a[i] + dp[i-1][0];
    }
    return max(dp[N][0], dp[N][1]);
  }
};


int main() {
  Solution s;
  vector<int> nums = {2, 2, 3, 3, 3, 4};
  cout << s.deleteAndEarn(nums) << endl;
  return 0;
}
