#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://discuss.leetcode.com/topic/58366/drop-eggs-dp-solution
//
// There is a building of N floors. If an egg drops from the k-th floor or above, it will break. If it's dropped from any floor below, it will not break. 
// You're given M eggs.
// You want to find out k, what is the minimum drops in worst case (all cases) ti find out k.
//
// DP, min-max
//      dp[n][m] means the minimal max drops we need if we have n-floor building and m eggs
//
//      dp[0][m] = 0 (m >= 1)
//      dp[n][1] = n (n >= 1)
//      for any floor i, we drop egg, if break, we need to solve [i-1,m-1] subproblem, if not broken, we need to solve [n-i][m] subproblem, we choose max of them two (worst case), and the result is the minimum i's turn
//      dp[n][m] = min(max(dp[i-1][m-1], dp[n-i][m])) + 1  


// Solution 1 : top-down dp + memo
class Solution_1 {
public:
    int drops(int N, int M) {
        vector<vector<int>> memo(N+1, vector<int>(M+1, -1));
        return dp(N, M, memo);
    }

    int dp(int n, int m, vector<vector<int>>& memo) {
        if (memo[n][m] != -1) return memo[n][m];
        if (n == 0) return memo[n][m] = 0;
        if (m == 1) return memo[n][m] = n;
        int res = INT_MAX;
        for (int i = 1; i <= n; ++i) 
            res = min(res, max(dp(i-1, m-1, memo), dp(n-i, m, memo)) + 1);
        memo[n][m] = res;
        return res;
    }
};

// Solution 2 : bottom-up dp
class Solution {
public:
    int drops(int N, int M) {
        vector<vector<int>> dp(N+1, vector<int>(M+1, -1));
        for (int j = 0; j <= M; ++j) dp[0][j] = 0;
        for (int i = 1; i <= N; ++i) dp[i][1] = i;

        for (int n = 1; n <= N; ++n) {
            for (int m = 2; m <= M; ++m) {
                dp[n][m] = INT_MAX;
                for (int i = 1; i <= n; ++i) {
                    dp[n][m] = min(dp[n][m], max(dp[i-1][m-1], dp[n-i][m]) + 1);
                }
            }
        }
        return dp[N][M];
    }
};


int main()
{
    Solution_1 s1;
    cout << s1.drops(10, 2) << endl;

    Solution s2;
    cout << s2.drops(10, 2) << endl;
	return 0;
}

