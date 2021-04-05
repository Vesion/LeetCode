#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Note the difference between this and 1406-StoneGameIII,
// this one needs to find the maximum stones of the first player,
// 1406 only needs to find whether the first player can win.

// Top down dp, O(n*n*n)
class Solution {
public:
    vector<vector<int>> dp;

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(2*n+1, vector<int>(2*n+1, -1));
        vector<int> sufsum = piles;
        for (int i = n-2; i >= 0; --i) sufsum[i] += sufsum[i+1];
        return dfs(sufsum, 0, 1);
    }

    // return maximum stones the player could get
    int dfs(const vector<int>& sufsum, int i, int m) {
        if (i >= sufsum.size()) return 0;
        if (dp[i][m] != -1) return dp[i][m];
        int rival = INT_MAX;
        for (int x = 1; x <= 2*m && i+x-1 < sufsum.size(); ++x) {
            rival = min(rival, dfs(sufsum, i+x, max(m, x)));
        }
        return dp[i][m] = sufsum[i]-rival;
    }
};

// Bottom up dp, O(n*n*n)
class Solution1 {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sufsum (n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            sufsum[i] = sufsum[i + 1] + piles[i];
        }
        vector<vector<int>>dp(n + 1, vector<int>(n + 1,0));
        for (int i = 0; i <= n; i++) {
            dp[i][n] = sufsum[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                for (int X = 1; X <= 2 * j && i + X <= n; X++) {
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
                }
            }
        }
        return dp[0][1];
    }
};

int main() {
    return 0;
}
