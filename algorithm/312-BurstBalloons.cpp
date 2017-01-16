#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Divide with the last bursted balloon.

// Solution 1 : top-down, recursive + memo
class Solution_1 {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(), 1), nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return burst(nums, 0, n-1, memo);
    }

    int burst(vector<int>& nums, int left, int right, vector<vector<int>>& memo) {
        if (left+1 >= right) return 0;
        if (memo[left][right]) return memo[left][right];
        int res = 0;
        for (int i = left+1; i < right; ++i) {
            res = max(res, burst(nums, left, i, memo) + burst(nums, i, right, memo) // calculate left half and right half recursively
                    + nums[left]*nums[i]*nums[right]); // and don't forget to add the final bursted one * left_boarder * right_border
        }
        memo[left][right] = res;
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
        nums.insert(nums.begin(), 1), nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 3; len <= n; ++len) {
            for (int left = 0; left+len <= n; ++left) {
                int right = left+len-1;
                for (int i = left+1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + nums[left]*nums[i]*nums[right]);
                }
            }
        }
        return dp[0][n-1];
    }
};


int main() {
    return 0;
}

