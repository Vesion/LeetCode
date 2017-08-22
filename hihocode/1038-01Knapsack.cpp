#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N, M;
int w[505], v[505];
int dp[100005];

int main() {
    cin >> N >> M;    
    for (int i = 0; i < N; ++i) cin >> w[i] >> v[i];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < N; ++i) {
        for (int j = M; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[M] << endl;
    return 0;
}
