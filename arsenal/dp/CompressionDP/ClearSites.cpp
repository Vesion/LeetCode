#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://hihocoder.com/problemset/problem/1044
// Problem:
//      Given N items with value v[i], we cannot choose more than Q items in continuous M items, what is the max value we can get.

int N, M, Q;
int v[1005];

// dp[i][j] means the solution for: 
//      when reach i, status of [i-M+1, i] is j (in binary)
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
    for (int i = 1; i <= N; ++i) cin >> v[i];
    int mask = (1<<M)-1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < (1<<M); ++j) { // enumerate all possible status of i-1
            // do not choose v[i]
            int j0 = (j<<1) & mask;
            dp[i][j0] = max(dp[i][j0], dp[i-1][j]);

            // choose v[i], but need to check status condition first
            int j1 = ((j<<1)+1) & mask;
            if (count(j1) <= Q) dp[i][j1] = max(dp[i][j1], dp[i-1][j]+v[i]);
        }
    }
    int res = 0;
    for (int j = 0; j < (1<<M); ++j) res = max(res, dp[N][j]);
    cout << res << endl; 
    return 0;
}

