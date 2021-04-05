#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, O(n*k) time, O(k) space
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<int> dp(k);
        for (int i = 0; i < k; ++i) dp[i] = costs[0][i];
        for (int i = 1; i < n; ++i) {
            vector<int> right(k, INT_MAX);
            for (int j = k-2; j >= 0; --j)
                right[j] = min(right[j+1], dp[j+1]);
            vector<int> left(k, INT_MAX);
            for (int j = 1; j < k; ++j)
                left[j] = min(left[j-1], dp[j-1]);
            for (int j = 0; j < k; ++j)
                dp[j] = min(left[j], right[j]) + costs[i][j];
        }
        return *min_element(dp.begin(), dp.end());
    }
};


int main() {
    return 0;
}
