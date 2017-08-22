#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N, W;
int dp[100005];
int w[505], v[505];

int main() {
    cin >> N >> W; 
    for (int i = 0; i < N; ++i) cin >> w[i] >> v[i];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < N; ++i) {
        for (int j = w[i]; j <= W; ++j) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}
