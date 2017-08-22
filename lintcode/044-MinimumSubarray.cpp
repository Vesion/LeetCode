#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSubArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = min(dp[i-1]+nums[i], nums[i]);
            result = min(result, dp[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
