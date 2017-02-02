#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : top-down, memo dp
class Solution_1 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        return dfs(nums, target, m);
    }
    
    int dfs(vector<int>& nums, int target, unordered_map<int,int>& m) {
        if (target == 0) return 1;
        if (m.count(target)) return m[target];
        int res = 0;
        for (int& num : nums) {
            if (target-num >= 0) res += dfs(nums, target-num, m);
            else break; // sort nums to stop early
        }
        m[target] = res;
        return res;
    }
};


// Solution 2 : bottom-up dp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int& num : nums) {
                if (i-num >= 0) dp[i] += dp[i-num];
                else break; // sort nums to stop early
            }
        }
        return dp[target];
    }
};


int main() {
    Solution s;
    vector<int> nums = {-2, 2};
    cout << s.combinationSum4(nums, 2) << endl;
    return 0;
}

