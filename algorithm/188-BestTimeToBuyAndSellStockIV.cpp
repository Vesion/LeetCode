#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 'Max Sum of K Subarrays'
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

        // dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
        // dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
        //          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
        vector<vector<int>> dp(k+1, vector<int>(n));
        for (int i = 1; i <= k; ++i) {
            int localMax = dp[i-1][0] - prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j-1], prices[j] + localMax);
                localMax = max(localMax, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }  
};

int main() {
    Solution s;
    return 0;
}

