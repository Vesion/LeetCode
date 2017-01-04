#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : top-down, memo dp
class Solution_1 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        return dfs(nums, target, dp);
    }
    
    int dfs(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];
        int res = 0;
        for (int& num : nums)
            if (num <= target) res += dfs(nums, target-num, dp);
        dp[target] = res;
        return res;
    }
};


// Solution 2 : bottom-up dp
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
    return 0;
}

