#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 21;
ll a[MAXN];
ll dp[MAXN][1<<MAXN];
ll sum[1<<MAXN];
int N;

int count1(int x) {
    int r = 0;
    while (x) { ++r; x &= (x-1); }
    return r;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    int M = 1<<N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (count1(j) == i) {
                for (int k = 0; k < N; ++k) {
                    if ((j>>k)&1) {
                        int oj = j ^ (1<<k);
                        dp[i][j] = max(dp[i][j], dp[i-1][oj]+sum[oj]%a[k]);
                        sum[j] = sum[oj]+a[k];
                    }
                }
            }
        }
    }

    cout << dp[N][M-1] << endl;
    return 0;
}
