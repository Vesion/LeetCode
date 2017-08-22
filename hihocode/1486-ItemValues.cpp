#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1005;
const int INF = 0x80000000;
int v[MAXN], p[MAXN];
int n, m;
int dp[MAXN][1<<11];

int main() {
    int T; cin >> T;
    while (T--) {
        memset(v, 0, sizeof v);
        memset(p, 0, sizeof p);
        memset(dp, -1, sizeof dp);
        cin >> n >> m; 
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            int s; cin >> s;
            while (s--) {
                int x; cin >> x;
                p[i] |= (1<<(x-1));
            }
        }

        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < (1<<m); ++j) {
                if (dp[i-1][j] != -1) {
                    dp[i][j^p[i]] = max(dp[i][j^p[i]], dp[i-1][j]+v[i]);
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
            }
        }
        cout << dp[n][(1<<m)-1] << endl;
    }
    return 0;
}
