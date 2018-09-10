#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/
// https://leetcode.com/problems/target-sum/
//
// Given a non-empty array containing only positive integers, check how many subsets of it sum to a specific target.
// 01 kanpsack

// bottom-up dp
class Solution {
public:
    int subsetSum(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int& num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] += dp[j-num];
            }
        }
        return dp[target];
    }
};


int main() {
    return 0;
}
