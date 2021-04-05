#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// from bottom row to top row
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle.back(); // init with the last row
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};


// from top row to bottom row
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size(), m = t.back().size();
        if (n == 1) return t[0][0];
        vector<int> dp(m, INT_MAX);
        dp[0] = t[0][0];
        int res = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) dp[j] += t[i][j];
                else dp[j] = min(dp[j], dp[j-1]) + t[i][j];
                if (i == n-1) res = min(res, dp[j]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
