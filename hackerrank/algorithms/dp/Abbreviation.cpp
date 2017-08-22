#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e3+5;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

bool solve() {
    int la = strlen(a), lb = strlen(b);
    dp[0][0] = 1;
    for (int i = 1; i <= la; ++i) dp[i][0] = 1;
    for (int i = 1; i <= la; ++i) {
        char ac = a[i-1];
        if (islower(ac)) {
            ac = toupper(ac);
            for (int j = 1; j <= lb; ++j) {
                if (ac == b[j-1] && dp[i-1][j-1]) dp[i][j] = 1;
                else if (dp[i-1][j]) dp[i][j] = 1;
            }
        } else {
            for (int j = 1; j <= lb; ++j) {
                if (ac == b[j-1] && dp[i-1][j-1]) dp[i][j] = 1;
            }
        }
    }
    return dp[la][lb];
}

int main() {
    int T; cin >> T;
    while (T--) {
        memset(dp, 0, sizeof dp);
        scanf("%s\n%s", a, b);
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
