#include <iostream>
#include <vector>
using namespace std;

// classic DP problem, 最大子段和问题
// dp[i] = max{dp[i-1] + nums[i], nums[i]}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int dp = 0;
        for (int num : nums) {
            dp = max(dp+num, num);
            res = max(res, dp);
        }
        return res;
    }
};


int main() {
    return 0;
}
