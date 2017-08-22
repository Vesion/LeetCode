#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 3005;
const ll INF = 1e18;
ll a[MAXN];
ll dp[MAXN][MAXN];
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a+N);

    fill_n((ll*)dp, MAXN*MAXN, INF);
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= min(i, K); ++j) {
            int my = j, his = i-j;
            if (my < K) {
                ll add = a[i]*his - a[i]*(N-K-his);
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+add);
            }
            if (his < N-K) {
                ll add = a[i]*my - a[i]*(K-my);
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+add);
            }
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}
