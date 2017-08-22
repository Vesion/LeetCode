#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 2100;
string a, b;
int m, n;
int f[MAXN][MAXN];
int dp[MAXN][MAXN][2];

int main() {
    cin >> a >> b;
    m = a.size(), n = b.size();

    // f[i][j] = the length of common suffix of a[0...i) and b[0...j)
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1]+1;
            else f[i][j] = 0;
        }
    }

    /* O(n^3)
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (f[i][j] >= 3) {
                for (int k = 3; k <= f[i][j]; ++k)
                    dp[i][j] = max(dp[i][j], dp[i-k][j-k] + k);
            }
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    */

    // O(n^2)
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (f[i][j] >= 3) {
                dp[i][j][1] = max(dp[i][j][1], dp[i-3][j-3][0]+3);
                if (f[i][j] > 3) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1]+1);
            }
            dp[i][j][0] = max(dp[i][j][1], max(dp[i-1][j][0], dp[i][j-1][0]));
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}
