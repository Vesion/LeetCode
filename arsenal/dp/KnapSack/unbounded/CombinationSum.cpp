#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/combination-sum-iv/
// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
// Each number can be used unlimited times.


// unbounded knapsack, but be careful with the loops' order
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
    return 0;
}
