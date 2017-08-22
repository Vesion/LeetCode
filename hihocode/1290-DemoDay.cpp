#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 102;

char g[MAX][MAX];
int dp[MAX][MAX][2];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> g[i][j];

    dp[0][0][0] = (g[0][0] == 'b');
    dp[0][0][1] = dp[0][0][0] + (m > 1 && g[0][1] == '.');

    for (int i = 1; i < n; ++i) {
        dp[i][0][1] = min(dp[i-1][0][1], dp[i-1][0][0] + (m > 1 && g[i-1][1] == '.')) + (g[i][0] == 'b');
        dp[i][0][0] = dp[i][0][1] + (i+1 < n && g[i+1][0] == '.');
    }
    for (int j = 1; j < m; ++j) {
        dp[0][j][0] = min(dp[0][j-1][0], dp[0][j-1][1] + (n > 1 && g[1][j-1] == '.')) + (g[0][j] == 'b');
        dp[0][j][1] = dp[0][j][0] + (j+1 < m && g[0][j+1] == '.');
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j][0] = min(dp[i][j-1][0], dp[i-1][j][1] + (i+1 < n && g[i+1][j] == '.')) + (g[i][j] == 'b');
            dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][0] + (j+1 < m && g[i][j+1] == '.')) + (g[i][j] == 'b');
        }
    }

    cout << min(dp[n-1][m-1][0], dp[n-1][m-1][1]) << endl;;
    return 0;
}
