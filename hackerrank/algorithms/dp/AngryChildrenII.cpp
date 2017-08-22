#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 1e5+5;
const ll INF = (ll)1e18;
ll a[MAXN];
ll sum[MAXN];
int N, K;

int main() {
    cin >> N >> K; 
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a+N);
    for (int i = 1; i <= N; ++i) sum[i] = sum[i-1]+a[i-1];

    ll res = INF, u = 0;
    for (int i = 0; i < N; ++i) {
        if (i < K-1) u += a[i]*i-sum[i]; 
        else u += a[i]*(K-1) - (sum[i]-sum[i-K+1]);
        if (i >= K) u -= (sum[i]-sum[i-K+1]) - a[i-K]*(K-1);
        if (i >= K-1) res = min(res, u);
    }
    cout << res << endl;
    return 0;
}
