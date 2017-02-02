#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <numeric> 
using namespace std;

// Solution 1 : trivial dfs
class Solution_1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, S);
    }
    
    int dfs(vector<int>& nums, int start, int sum) {
        if (start == (int)nums.size()) {
            if (sum == 0) return 1;
            return 0;
        }
        int res = 0;
        res += dfs(nums, start+1, sum-nums[start]);
        res += dfs(nums, start+1, sum+nums[start]);
        return res;
    }
};


// Solution 2 : dp
// dp[i][j] = the solution for reaching nums[i], sum is j
class Solution_2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (auto& p : dp[i-1]) {
                int sum = p.first, cnt = p.second;
                dp[i][sum-nums[i-1]] += cnt;
                dp[i][sum+nums[i-1]] += cnt;
            }
        }
        return dp[n][S];
    }
};


// Solution 3 : dp, convert it to 'Subset Sum Problem' (like 416-PartitionEqualSubsetSum)
// tricky, need to preprocess
//
// Firstly, the 'subset sum problem' is given a positive array, find all subsets of it whose sum is a given target
// How to convert our problem to subset sum problem?
// After allocating signs, the original nums can be divided into two subsets, P and N
//      P is the subset whose element given '+' sign
//      N is the subset whose element given '-' sign 
// So, we now need to find all dividing solutions make P - N = S, then
//      P - N = S
//      P + P = S + P + N = S + sum
//          P = (S + sum) / 2
// We are done! After the conversion, our new target S is (S + sum) / 2, and it's a real subset sum problem!
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S < -sum || S > sum || (S+sum)&1) return 0; // invalid S
        S = (S + sum) / 2;

        vector<int> dp(S+1, 0);
        dp[0] = 1;
        for (int& num : nums) {
            for (int i = S; i >= num; --i) {
                dp[i] += dp[i-num];
            }
        }
        return dp[S];
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(nums, 3) << endl;
    return 0;
}
