#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// same with 1406-StoneGameIII

// top-down dp
class Solution {
public:
    vector<int> sums;
    vector<vector<int>> dp;

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        sums.resize(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + stones[i-1];
        dp.resize(n+1, vector<int>(n+1, INT_MIN));
        return game(1, n);
    }

    int game(int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        int d1 = (sums[j]-sums[i] - game(i+1, j));
        int d2 = (sums[j-1]-sums[i-1] - game(i, j-1));
        return dp[i][j] = max(d1, d2);
    }
};


// bottom-up dp
class Solution2 {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + stones[i-1];

        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));
        for (int i = 0; i <= n; ++i) dp[i][i] = 0;
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i+len-1 <= n; ++i) {
                int j = i+len-1;
                int d1 = sums[j]-sums[i] - dp[i+1][j];
                int d2 = sums[j-1]-sums[i-1] - dp[i][j-1];
                dp[i][j] = max(d1, d2);
            }
        }
        return dp[1][n];
    }
};

int main() {
}
