#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set> 
using namespace std;

using ll = long long;
const int MAXN = 255;
ll a[MAXN][MAXN];
ll N, M, K;

int maxLength(int row) {
    vector<int> sums(M+1, 0);
    for (int i = 1; i <= M; ++i) sums[i] = sums[i-1]+a[row][i-1];
    int res = 0;
    for (int i = 1; i <= M; ++i) {
        auto it = lower_bound(sums.begin(), sums.end(), sums[i]-K);
        if (it != sums.end()) res = max(res, i-(int)(it-sums.begin()));
    }
    return res;
}

int main() {
    cin >> N >> M >> K;    
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> a[i][j];
    int res = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (i != j) a[i][k] += a[j][k];
            }
            int len = maxLength(i);
            if (len) res = max(res, len*(j-i+1));
        }
    }
    cout << res << endl;
    return 0;
}

