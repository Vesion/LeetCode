#include <iostream>
#include <vector>
using namespace std;

// dp, dp[i] represents the max money robbed before i houses
//      if rob house i, house i-1 must not be robbed, dp[i] = dp[i-2]+nums[i];
//      if not rob house i, house i-1 can be robbed, dp[i] = dp[i-1]
//      so dp[i] is max of above two
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i)
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    return dp[n-1];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << rob(nums) << endl;
    return 0;
}
