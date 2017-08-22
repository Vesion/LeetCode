#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int dp[51][51][51] = {{{0}}};
        int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        dp[0][i][j] = 1;
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i+go[d][0], nj = j+go[d][1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) ni = m, nj = n;
                        add(dp[k+1][ni][nj], dp[k][i][j]);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) add(res, dp[i][m][n]);
        return res;
    }

    void add(int& a, int b) {
        a += b;
        if (a >= 1e9+7) a -= 1e9+7;
    }
};

int main() {
    Solution s;
    cout << s.findPaths(2,2,2,0,0) << endl;;
    return 0;
}
