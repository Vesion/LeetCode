#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : naive dfs, TLE
class Solution_dfs {
public:
    int result = 0;
    void dfs(vector<int>& nums, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            result++;
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            dfs(nums, sum+nums[i], target);
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return result;
    }
};


// Solution 1.0 : dp, top-down, TLE
class Solution_topdown {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 1;
        int result = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] <= target)
                result += combinationSum4(nums, target-nums[i]);
        }
        return result;
    }
};


// Solution 1.1 : dp, bottom-up
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= nums[j])
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 2, 1};
    cout << s.combinationSum4(nums, 32) <<endl;
    return 0;
}
