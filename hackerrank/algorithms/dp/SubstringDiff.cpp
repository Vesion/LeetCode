#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 1505;
char a[MAXN], b[MAXN];
struct State {
    int l, s;
} dp[MAXN][MAXN];

int main() {
    int T; cin >> T;
    while (T--) {
        memset(dp, 0, sizeof dp);
        int S; cin >> S;
        scanf("%s", a); scanf("%s", b);
        int n = strlen(a);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j].l = dp[i-1][j-1].l+1;
                dp[i][j].s = dp[i-1][j-1].s + (a[i-1]==b[j-1] ? 0 : 1);
                while (dp[i][j].s > S) {
                    if (a[i-dp[i][j].l] != b[j-dp[i][j].l]) --dp[i][j].s;
                    --dp[i][j].l;
                }
                res = max(res, dp[i][j].l);
            }
        }
        cout << res << endl;
    }
    return 0;
}
