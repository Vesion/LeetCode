#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 1000;
int v[MAXN];
ll dp[MAXN];
int N, M;

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; ++i) cin >> v[i];
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = v[i]; j <= M; ++j) dp[j] += dp[j-v[i]];
    }
    cout << dp[M] << endl;
    return 0;
}
