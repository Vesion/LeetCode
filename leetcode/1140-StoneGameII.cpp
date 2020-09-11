#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Top down dp, O(n*n*n)
class Solution {
public:
    static constexpr int MAX = 202;
    int dp[MAX][MAX] = {0};

    int stoneGameII(vector<int>& piles) {
        vector<int> sufsums = piles;
        for (int i = sufsums.size()-2; i >= 0; --i) sufsums[i] += sufsums[i+1];
        return dfs(sufsums, 0, 1);
    }

    int dfs(const vector<int>& sufsums, int s, int m) {
        if (dp[s][m]) return dp[s][m];
        if (s >= sufsums.size()) return 0;

        int min_rival = sufsums[0];
        for (int x = 1; x <= 2*m && s-1+x < sufsums.size(); ++x) {
            min_rival = min(min_rival, dfs(sufsums, s+x, max(m,x)));
        }
        dp[s][m] = sufsums[s] - min_rival;
        return dp[s][m];
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
