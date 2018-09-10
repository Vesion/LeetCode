#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://agc013.contest.atcoder.jp/tasks/agc013_d

using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 3005;
ll dp[MAXN][MAXN][2];
int n, m;

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}


int main() {
    cin >> n >> m;
    for (int j = 0; j <= n; ++j) dp[0][j][j == 0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int j1 = 0; j1 <= 1; ++j1) for (int j2 = 0; j2 <= 1; ++j2) {
                    if (j == 0 && j1) continue;
                    if (j == n && !j1) continue;
                    int nj = j+1-j1-j2;
                    int nk = k || (j == j1);
                    add(dp[i+1][nj][nk], dp[i][j][k]);
                }
            }
        }
    }

    ll res = 0;
    for (int j = 0; j <= n; ++j) add(res, dp[m][j][1]);
    cout << res << endl;
    return 0;
}
