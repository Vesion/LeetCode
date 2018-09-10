#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://hihocoder.com/problemset/problem/1486
// similar to 1044-ClearSites
//
// Problem:
//      Given n items with value[i] and properties[i] (means it has some properties), there are totally m properties. How to pick items to ensure maximum value and every properties has odd items choosing it.
//
// Solution:
//      At first look, it's a variant of 01-kanpsack, but here we don't have weight but property, how to state it?
//      Note m is no more than 10, it's a good hint that we can use bit to represent property status and XOR to transfer status, and the final status is (1<<m)-1 (all odd).

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
            for (int j = 0; j < (1<<m); ++j) { // enumerate all possible status of i-1
                if (dp[i-1][j] != -1) {
                    // choose i
                    dp[i][j^p[i]] = max(dp[i][j^p[i]], dp[i-1][j]+v[i]);

                    // do not choose i
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
            }
        }
        cout << dp[n][(1<<m)-1] << endl;
    }
    return 0;
}

