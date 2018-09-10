#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://hihocoder.com/problemset/problem/1048
// Problem:
//      Given a n*m grid, and infinite 1*2 and 2*1 tile, what is the total number of putting tiles fully in the grid.

const int MOD = 1000000007;
int n, m;

// dp[i][j] meas the solution for:
//      when reach ith row, the status of ith and (i+1)th row is j, the lower m bits for ith row, the higher m bits for (i+1)th row
int dp[1005][1<<11];

int main() {
    memset(dp, 0, sizeof dp);
    cin >> n >> m; 
    int full = (1<<m)-1;
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int s = 0; s < (1<<(2*m)); ++s) { // enumerate all possible status
                if ((s & (1<<j)) == 0) { // if current column is empty
                    int sv = s | (1<<j) | (1<<(j+m)); // we can definitely put a tile vertically
                    dp[i][sv] = (dp[i][sv] + dp[i][s]) % MOD;

                    if (j+1 < m && (s & (1<<(j+1))) == 0) { // if next column is empty
                        int sh = s | (1<<j) | (1<<(j+1)); // we can put a tile horizontally
                        dp[i][sh] = (dp[i][sh] + dp[i][s]) % MOD;
                    }
                }
            }
        }
        // transfer those full status of current row to next row
        for (int s = 0; s < (1<<(2*m)); ++s) {
            if ((s & full) == full) dp[i+1][s>>m] = dp[i][s];
        }
    }

    cout << dp[n-1][full] << endl;
    return 0;
}

