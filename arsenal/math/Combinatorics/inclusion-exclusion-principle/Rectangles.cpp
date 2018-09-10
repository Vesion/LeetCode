#include <iostream> 
using namespace std;

// http://hihocoder.com/problemset/problem/1476

using ll = long long;
const int MOD = 1000000007;

int main() {
    int N, M, K, x[20], y[20];
    cin >> N >> M >> K;
    for (int i = 0; i < K; i ++) cin >> x[i] >> y[i];

    ll total = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            total += (N - i + 1) * (M - j + 1);
        }
    }

    ll invalid = 0;
    for (int s = 1; s < (1 << K); s ++) {
        int X1 = 100000, X2 = -1;
        int Y1 = 100000, Y2 = -1;
        int cnt = 0;
        for (int i = 0; i < K; i ++)
        if ((s >> i) & 1) {
            X1 = min(X1, x[i]);
            X2 = max(X2, x[i]);
            Y1 = min(Y1, y[i]);
            Y2 = max(Y2, y[i]);
            cnt ++;
        }
        if (cnt & 1) {
            invalid += (ll)X1 * Y1 * (N - X2 + 1) * (M - Y2 + 1);
        } else {
            invalid -= (ll)X1 * Y1 * (N - X2 + 1) * (M - Y2 + 1);
        }
    }

    cout << total-invalid << endl;
    return 0;
}


