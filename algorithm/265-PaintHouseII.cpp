#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(n*k*k) time, O(n*k) space
class Solution_1 {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        vector<int> mincost(k, 0);
        for (int j = 0; j < k; ++j) dp[0][j] = costs[0][j];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = INT_MAX;
                for (int l = 0; l < k; ++l) if (l != j) dp[i][j] = min(dp[i][j], dp[i-1][l]);
                dp[i][j] += costs[i][j];
            }
        }
        int res = INT_MAX;
        for (int i : dp[n-1]) res = min(res, i);
        return res;
    }
};


// Solution 2 : O(n*k) time, O(k) space
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size();

        int res = INT_MAX;
        vector<int> dp(k);
        for (int j = 0; j < k; ++j) {
            dp[j] = costs[0][j];
            if (n == 1) res = min(res, dp[j]);
        }

        vector<int> left(k), right(k);
        for (int i = 1; i < n; ++i) {
            left[0] = right[k-1] = INT_MAX;
            for (int j = 1; j < k; ++j) left[j] = min(dp[j-1], left[j-1]);
            for (int j = k-2; j >= 0; --j) right[j] = min(dp[j+1], right[j+1]);

            for (int j = 0; j < k; ++j) {
                dp[j] = min(left[j], right[j]) + costs[i][j];
                if (i == n-1) res = min(res, dp[j]);
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> c = {{1,5,3},{2,9,4}};
    Solution_1 s1;
    cout << s1.minCostII(c) << endl;

    Solution s;
    cout << s.minCostII(c) << endl;
    return 0;
}

