#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// NP hard, DFS
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum%k) return false;
        return dfs(nums, 0, 0, sum/k, k, 0);
    }

    bool dfs(const vector<int>& nums, int start, int sum, int target, int k, int vis) {
        if (k == 1) return true;
        if (sum == target) return dfs(nums, 0, 0, target, k-1, vis);
        if (start == nums.size()) return false;
        for (int i = start; i < nums.size(); ++i) {
            if (vis & (1<<i)) continue;
            if (dfs(nums, i+1, sum+nums[i], target, k, vis|(1<<i))) return true;
        }
        return false;
    }
};


// DP
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/480707/C%2B%2B-DP-bit-manipulation-in-20-lines
class Solution {
public:
    int dp[(1<<16)+2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;

        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};

int main() {
}
