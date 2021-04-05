#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/burst-balloons/
// Divide with the last bursted balloon.

// Solution 1 : top-down + memoization
class Solution_1 {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> m(n, vector<int>(n, 0));
        return dfs(nums, 0, n-1, m);
    }
    
    int dfs(vector<int>& nums, int left, int right, vector<vector<int>>& m) {
        if (left+1 >= right) return 0; // at leat 3 ballons
        if (m[left][right]) return m[left][right];
        int res = 0;
        for (int i = left+1; i <= right-1; ++i) {
            res = max(res, dfs(nums, left, i, m) + dfs(nums, i, right, m) + nums[left]*nums[i]*nums[right]);
        }
        m[left][right] = res;
        return res;
    }
};


// Solution 2 : bottom-up, interval dp
//      dp[i][j] = the max money of bursting the kth ballon in range (i, j) exclusive
//      dp[i][j] = max(dp[i][k], dp[k][j]) + nums[i]*nums[k]*nums[j]
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                for (int k = i+1; k <= j-1; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};


int main() {
    return 0;
}
