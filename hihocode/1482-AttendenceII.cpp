#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 100005;
const int MOD = 1e9 + 7;

// dp[i][j][k] = the number of sequences when reach i, we have j 'A's till now (at most 1), and k 'L's in S[i-1...i] (at most 2)
int dp[MAXN][2][3];
int N;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    memset(dp, 0, sizeof dp);
    cin >> N;

    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 2; ++k) {
                add(dp[i+1][j][0], dp[i][j][k]); // put 'O' on next i
                if (j == 0) add(dp[i+1][1][0], dp[i][j][k]); // put 'A' on next i
                if (k != 2) add(dp[i+1][j][k+1], dp[i][j][k]); // put 'L' on next i
            }
        }
    }
    int res = 0;
    for (int j = 0; j <= 1; ++j)
        for (int k = 0; k <= 2; ++k) add(res, dp[N][j][k]);
    cout << res << endl;
    return 0;
}
