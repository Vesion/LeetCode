#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// variant of 1423-MaximumPointsYouCanObtainFromCards

// DP, top-down
class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size(), m = multipliers.size();
        dp.resize(m, vector<int>(m, INT_MIN));
        return dfs(nums, multipliers, 0, 0);
    }

    int dfs(const vector<int>& nums, const vector<int>& mul, int i, int k) {
        if (k >= m) return 0;
        if (dp[i][k] != INT_MIN) return dp[i][k];

        int j = n-1-(k-i);
        dp[i][k] = max(dfs(nums, mul, i+1, k+1) + nums[i]*mul[k],
                       dfs(nums, mul, i, k+1) + nums[j]*mul[k]);
        return dp[i][k];
    }
};

// DP, bottom-up
class Solution1 {
public:
    int maximumScore(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<int> dp(m + 1);
        for (int sz = n - m + 1; sz <= n; sz++) {
            for (int i = 0, j = i + sz - 1; j < n; i++, j++) {
                dp[i] = max(
                    A[i] * B[n - sz] + dp[i + 1],
                    A[j] * B[n - sz] + dp[i]
                );
            }
        }
        return dp[0];
    }
};

int main() {

}