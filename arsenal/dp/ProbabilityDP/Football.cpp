#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://poj.org/problem?id=3071

const int MAX = (1<<7)+5;
double p[MAX][MAX];
double dp[10][MAX];
int n;

int main() {
    while (cin >> n && n != -1) {
        memset(dp, 0, sizeof dp);
        int m = 1<<n;
        for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) cin >> p[i][j];

        for (int j = 0; j < m; ++j) dp[0][j] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (((j>>(i-1)) ^ (k>>(i-1))) == 1)
                        dp[i][j] += dp[i-1][j]*dp[i-1][k]*p[j][k];
                }
            }
        }
        int res = 0; double w = 0;
        for (int j = 0; j < m; ++j) if (dp[n][j] > w) { w = dp[n][j]; res = j+1; }
        cout << res << endl;
    }
    return 0;
}
