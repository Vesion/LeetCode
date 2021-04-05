#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DP, O(k*n*n)
class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        constexpr int go[8][2] = {
            {-2,-1}, {-2,1}, {-1,2}, {1, 2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}
        };
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][col] = 1;
        for (int t = 0; t < k; ++t) {
            vector<vector<double>> ndp(n, vector<double>(n, 0));
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
                for (int d = 0; d < 8; ++d) {
                    int oi = i+go[d][0], oj = j+go[d][1];
                    if (oi < 0 || oi >= n || oj < 0 || oj >= n) continue;
                    ndp[i][j] += dp[oi][oj] * (1.0 / 8);
                }
            }
            swap(dp, ndp);
        }
        double res = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) res += dp[i][j];
        return res;
    }
};


int main() {
  return 0;
}

