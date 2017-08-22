#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : top-down + memo
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
// similar to complete knapsack
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int& num : nums) {
                if (i >= num) dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};

// Note: solution below is written like the standard complete knapsack template, note the loops' order
// but it gets wrong answer, why?
// because the problem requires to find all possible combinations, including duplicates
//      e.g. nums = [1, 2, 3], target = 4  -->  solution above returns 6, but below returns 4, (1+3 and 3+1 count as two combinations, etc)
// so solution below only counts unique combinations
class Solution_wrong {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int& num : nums) {
            for (int j = num; j <= target; ++j) {
                dp[j] += dp[j-num];
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
