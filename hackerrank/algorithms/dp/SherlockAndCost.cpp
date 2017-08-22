#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int b[MAXN];
int dp[MAXN][2];
int N;

int main() {
    int T; cin >> T; 
    while (T--) {
        memset(dp, 0, sizeof dp);
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> b[i];

        for (int i = 2; i <= N; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+abs(1-b[i-1]));
            dp[i][1] = max(dp[i-1][0]+abs(b[i]-1), dp[i-1][1]+abs(b[i]-b[i-1]));
        }
        cout << max(dp[N][0], dp[N][1]) << endl;
    }
    return 0;
}
