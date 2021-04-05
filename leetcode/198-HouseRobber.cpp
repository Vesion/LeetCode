#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int norob = 0, rob = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int norob_t = norob;
            norob = max(norob_t, rob);
            rob = norob_t + nums[i];
        }
        return max(rob, norob);
    }
};


// Solution 2 : O(n) space
class Solution_2 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


int main() {
    return 0;
}
