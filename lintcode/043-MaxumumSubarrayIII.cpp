#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> nums, int k) {
        if (nums.empty() || k <= 0) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1));

        for (int j = 1; j <= k; ++j) {
            for (int i = j; i <= n; ++i) {
                dp[i][j] = INT_MIN;
                int local = 0, global = INT_MIN;
                for (int m = i-1; m >= j-1; --m) {
                    local = max(local+nums[m], nums[m]);
                    global = max(global, local);
                    dp[i][j] = max(dp[i][j], dp[m][j-1]+global);
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    Solution s;
    return 0;
}
