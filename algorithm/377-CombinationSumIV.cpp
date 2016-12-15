#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, similar to complete knapsack problem
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) dp[i] += dp[i-num]; // all solutions to (i-num) add num are also solve i
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.combinationSum4(nums, 4);
    return 0;
}

