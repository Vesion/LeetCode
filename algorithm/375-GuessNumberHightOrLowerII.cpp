#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Game theory, MinMax theory.
//
// dp[i][j] means the minimum money to guarantee win for subproblem [i, j]
// Our target is dp[1][n]
//
// For [i, j], we can choose k (i<=k<=j) as our guess, and pay k money. After that, the problem is divided into two subproblems [i, k-1] and [k+1, j].
// Notice we do not need to pay the money for both subproblems (because we are smart to choose the correct half according to the lower or higher feedback).
// We only need to pay the larger one to guarantee win. (The Max)
// After trying every k, we maintain the minimum money we need to pay. (The Min)
//
// So dp[i][j] = min{ k + max(dp[i][k-1], dp[k+1][j]) } i <= k <= j
//
// Generally, for each strategy, we calculate the worst case of it. After collecting results of all strategies, we pick the best one. 
// This is MinMax.


// Solution 1 : dp, top-down with memo
class Solution_1 {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return win(1, n, dp);
    }

    int win(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) return 0;
        if (dp[start][end]) return dp[start][end];
        int res = INT_MAX;
        for (int i = start; i <= end; ++i) {
            int t = i + max(win(start, i-1, dp), win(i+1, end, dp));
            res = min(res, t);
        }
        dp[start][end] = res;
        return res;
    }
};


// Solution 2 : dp, bottom-up
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int j = 2; j <= n; ++j) {
            for (int i = j-1; i >= 1; --i) {
                int global_min = INT_MAX;
                for (int k = i+1; k < j; ++k) {
                    int local_max = k + max(dp[i][k-1], dp[k+1][j]);
                    global_min = min(global_min, local_max);
                }
                dp[i][j] = i == j-1 ? i : global_min;
            }
        }
        return dp[1][n];
    }
};

int main() {
    Solution s;
    return 0;
}

