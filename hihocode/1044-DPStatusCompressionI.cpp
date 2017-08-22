#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N, M, Q;
int w[1005];

// dp[i][j] means the solution for: when reach i, status of [i-M+1, i] is j (in binary)
int dp[1005][1<<11];

int count(int s) {
    int c = 0;
    while (s) {
        ++c;
        s &= (s-1);
    }
    return c;
}

int main() {
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++i) cin >> w[i];
    int mask = (1<<M)-1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < (1<<M); ++j) { // try all possible status of i-1
            // do not choose w[i]
            int s0 = (j<<1) & mask;
            dp[i][s0] = max(dp[i][s0], dp[i-1][j]);

            // choose w[i], but need to check status condition first
            int s1 = ((j<<1)+1) & mask;
            if (count(s1) <= Q) dp[i][s1] = max(dp[i][s1], dp[i-1][j]+w[i]);
        }
    }
    int res = 0;
    for (int j = 0; j < (1<<M); ++j) res = max(res, dp[N][j]);
    cout << res << endl; 
    return 0;
}
