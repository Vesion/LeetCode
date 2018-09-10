#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cstring> 
using namespace std;

// http://blog.csdn.net/m0_37846371/article/details/72830913

const int MAXN = 55;
int n;
int a[MAXN];
int sum[MAXN];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }

    // dp[i][j] = the maximum height of the higher stack with height difference of j
    // in case of MLE, use scrolling array
    vector<vector<int>> dp(2, vector<int>(sum[n]*2+1, 0x80000000));
    dp[0][0] = 0;
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum[i]; j >= 0; --j) {
            dp[p][j] = max(dp[1-p][j], dp[1-p][j+a[i]]); // don't use ith brick, or put it on lower stack and still lower
            if (j >= a[i]) dp[p][j] = max(dp[p][j], dp[1-p][j-a[i]]+a[i]); // put ith brick on higher stack and still higher
            else dp[p][j] = max(dp[p][j], dp[1-p][a[i]-j]+j); // put ith brick on lower stack and turns into higher stack
        }
        p = 1-p;
    }

    if (dp[1-p][0] > 0) cout << dp[1-p][0] << endl;
    else cout << -1 << endl;
    return 0;
}
