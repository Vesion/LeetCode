#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DP, O(N)
// dp[i][j] = the length of side of max square with matrix[i][j] at bottom right position
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) dp[i][0] = matrix[i][0];
        for (int j = 0; j < n; ++j) dp[0][j] = matrix[0][j];
        for (int i = 1; i < m; ++i) for (int j = 1; j < n; ++j) {
            if (matrix[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
            res += dp[i][j];
        return res;
    }
};

int main() {

}
