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
// For [i, j], we can choose k (i<=k<=j) as our guess, and pay k money.
// After that, the problem is divided into two subproblems [i, k-1] and [k+1, j].
// Notice we do not need to pay the money for both subproblems (because we are smart to choose
// the correct half according to the lower or higher feedback).
//
// We only need to pay the larger one to guarantee win. (The Max)
// After trying every k, we maintain the minimum money we need to pay. (The Min)
//
// So dp[i][j] = min{ k + max(dp[i][k-1], dp[k+1][j]) } i <= k <= j
//
// Generally, for each strategy, we calculate the worst case of it.
// After collecting results of all strategies, we pick the best one.
// This is MinMax.


// Solution 1 : dp, top-down with memo
class Solution1 {
public:
    vector<vector<int>> dp;
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        return dfs(1, n);
    }

    int dfs(int lower, int upper) {
        if (lower >= upper) return 0;
        if (dp[lower][upper] != -1) return dp[lower][upper];
        int res = INT_MAX;
        for (int i = lower; i <= upper; ++i) {
            res = min(res, i + max(dfs(lower, i-1), dfs(i+1, upper)));
        }
        return dp[lower][upper] = res;
    }
};


// Solution 2 : dp, bottom-up
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i+len-1 <= n; ++i) {
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], max(i < k-1 ? dp[i][k-1] : 0, k+1 < j ? dp[k+1][j] : 0) + k);
                }
            }
        }
        return dp[1][n];
    }
};


int main() {
    return 0;
}
