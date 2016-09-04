#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// It's not easy to understand the problem definition, especially the 'Minimax' in hints.
//
// https://discuss.leetcode.com/topic/51494/java-commented-dp-solution
//
// https://www.wikiwand.com/en/Minimax
//      In simple words, 'Minimax' is the minimum cost you will pay in worst scenario, with best(maximum) strategy (here is the binary search strategy)).

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int j = 2; j <= n; ++j) {
            for (int i = j-1; i >= 1; --i) { // dp[i][j]
                if (i+1 == j) { dp[i][j] = i; continue; }
                dp[i][j] = INT_MAX;
                for (int k = i+1; k < j; ++k) {
                    int local = k + max(dp[i][k-1], dp[k+1][j]);
                    dp[i][j] = min(dp[i][j], local);
                }
            }
        }

        return dp[1][n];
    }
};

int main() {
    Solution s;
    cout << s.getMoneyAmount(2) <<endl;
    return 0;
}
