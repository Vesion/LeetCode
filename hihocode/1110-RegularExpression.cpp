#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 105;
char s[MAXN];
int dp[MAXN][MAXN];

bool solve() {
    int n = strlen(s);
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i+len-1 < n; ++i) {
            int j = i+len-1;
            if (i == j) dp[i][j] = (s[i] == '0' || s[i] == '1');
            else {
                if (s[i] == '(' && s[j] == ')' && dp[i+1][j-1]) dp[i][j] = 1;
                else if (s[j] == '*' && dp[i][j-1]) dp[i][j] = 1;
                else {
                    for (int k = i; k < j; ++k) {
                        if (dp[i][k] && dp[k+1][j]) dp[i][j] = 1;
                        if (s[k] == '|' && dp[i][k-1] && dp[k+1][j]) dp[i][j] = 1;
                    }
                }
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    while (scanf("%s", s) != EOF) {
        memset(dp, 0, sizeof dp);
        bool r = solve();
        if (r) cout << "yes" << endl;
        else cout << "no" << endl;
    } 
    return 0;
}
