#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 205;
const int INF = 0x7fffffff;

int main() {
    int dp[MAX][MAX];    
    int N; cin >> N;
    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i+len-1 <= N; ++i) {
            int j = i+len-1;
            dp[i][j] = INF;
            for (int k = i; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], max(i > k-1 ? 0 : dp[i][k-1], k+1 > j ? 0 : dp[k+1][j]) + k);
            }
        }
    }
    cout << dp[1][N] << endl;
    return 0;
}
