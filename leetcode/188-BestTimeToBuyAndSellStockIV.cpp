#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 'Max Sum of K Subarrays'
//
// dp[i][j] represents the max profit at day j with at most i transactions
// so, at day j, we have two choices:
//      1. do nothing, dp[i][j] = dp[i][j-1]
//      2. sell stock with prices[j], this means before day j we have i-1 transactions, also means we bought stock before day j, say we bought stock at day jj, 
//         then dp[i][j] = dp[i-1][jj-1] - prices[j]] + prices[j]
//         so, we have to choose one day which can maximize our profit, just iterate jj from 0 to j-1
//         dp[i][j] = max(dp[i-1][jj-1] - prices[jj]) + prices[j]
//
// combine above two:
//      dp[i][j] = max( dp[i][j-1], max(dp[i-1][jj-1]-prices[jj])+prices[j] ), jj in [0, j-1]
//
// the naive dp is O(n^3), but we can reduce to O(n^2)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // if k > n/2, it means that I can buy in every day and sell out next day
        // then the problem is same to 122, just be greedy
        if (k > n/2) {
            int result = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i-1]) result += (prices[i] - prices[i-1]);
            return result;
        }

        vector<vector<int>> dp(k+1, vector<int>(n));
        for (int i = 1; i <= k; ++i) {
            int preMax = dp[i-1][0] - prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j-1], preMax + prices[j]);
                preMax = max(preMax, dp[i-1][j-1] - prices[j]);
            }
        }
        return dp[k][n-1];
    }  
};


int main() {
    return 0;
}
