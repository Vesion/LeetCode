#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/predict-the-winner/
// Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
//
// similar to 464-CanIWin, but it has big difference:
//
// In 464, two player both contribute to one common sum, we only need to maintain one sum and no need to distinguish current player
//
// But here, two players contribute to their own sum, and their win conditions are different
//      for player1, sum1 >= sum2
//      for player2, sum2 > sum1
// Furthermore, here two players must pick all of the numbers, so our termination condition is left > right
// Therefore, we need two sums and need to distinguish current player.
// 
// Solution 1 : trivial recursive solution without memo
//      if use memo, we need a 3-D array m[left][right][p1] to cache states
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return win(nums, 0, nums.size()-1, 0, 0, true);
    }
    
    bool win(vector<int>& nums, int left, int right, int sum1, int sum2, bool p1) {
        if (left > right) {
            if (p1) return sum1 >= sum2;
            else return sum2 > sum1;
        }
        bool res = false;
        if (p1) res = !win(nums, left+1, right, sum1+nums[left], sum2, !p1) || !win(nums, left, right-1, sum1+nums[right], sum2, !p1);
        else res = !win(nums, left+1, right, sum1, sum2+nums[left], !p1) || !win(nums, left, right-1, sum1, sum2+nums[right], !p1);
        return res;
    }
};


// Now let's think about how to deal with it using dp
// Assume dp[i][j] means the maximum sum that Player 1 could get for subproblem [i, j]
//      if dp[0][n-1] >= TotalSum/2, Player 1 win
// then dp[i-1][j] and dp[i][j-1] are solution for Plyaer 2
// our dp formula is:
//      dp[i][j] = max(nums[i] + sum[i+1][j]-dp[i+1][j], nums[j] + sum[i][j-1]-dp[i][j-1])
// we can preprocess prefix/suffix sum so that we can solve the problem in O(n^2)
//
// 
// But how to solve it without preprocessing sum?
// Insteand of using dp to store the max sum of Player 1, we can use dp to store difference
// dp[i][j] = sum of player 1 - sum of player 2, for subproblem [i, j]
//      dp[i][j] = max( nums[i] - dp[i+1][j], nums[j] - dp[i][j-1] )


// Solution 2 : top-down dp + memo
// https://discuss.leetcode.com/topic/76312/java-1-line-recursion-solution
class Solution_2 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> m(n, vector<int>(n, -1));
        return diff(nums, 0, n-1, m) >= 0;
    }
    
    // plus gain in this turn, minus opponent's gain in next turn
    // choose the max selection (optimal)
    int diff(vector<int>& nums, int left, int right, vector<vector<int>>& m) {
        if (left == right) return nums[left];
        if (m[left][right] != -1) return m[left][right];
        int res = max(nums[left]-diff(nums, left+1, right, m), nums[right]-diff(nums, left, right-1, m));
        m[left][right] = res;
        return res;
    }
};


// Solution 3 : bottom-up dp
// https://discuss.leetcode.com/topic/76327/c-dp-solution-with-explanation
class Solution_3 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // dp[i][j] means the the difference between sum1 and sum2
        // so if dp[0][n-1] >= 0, it means the final sum1 >= sum2
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};


int main() {
    return 0;
}
