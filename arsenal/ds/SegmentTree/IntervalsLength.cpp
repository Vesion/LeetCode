#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

// From Google Code Jam
// https://code.google.com/codejam/contest/5254487/dashboard#s=p2

using ll = long long;

const int maxn = 1 << 20;
int L[maxn], R[maxn];
int X[maxn];
int sum[(maxn << 2) + 7];
int cnt[(maxn << 2) + 7];

int result;

void push_up(int l, int r, int i) {
	if (cnt[i]) sum[i] = X[r] - X[l];	
	else {
        if (l == r) sum[i] = 0;
        else sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
}

void update(int L, int R, int v, int l, int r, int i) {
	if (L <= l && r <= R) {
		cnt[i] += v;
		push_up(l, r, i);
		return;
	}
	int m = (l + r) / 2;
	if (L < m) update(L, R, v, l, m, i * 2);
	if (R > m) update(L, R, v, m, r, i * 2 + 1);
	push_up(l, r, i);
}

void solve() {
    ll N, L1, R1, A, B, C1, C2, M; 
    cin >> N >> L1 >> R1 >> A >> B >> C1 >> C2 >> M;
    ll x = L1, y = R1;
    L[1] = L1, R[1] = R1;
    for (int i = 2; i <= N; ++i) {
        ll xi = ( A*x + B*y + C1 ) % M;
        ll yi = ( A*y + B*x + C2 ) % M;
        L[i] = min(xi, yi), R[i] = max(xi, yi);
        x = xi, y = yi;
    }
    
    int S = 0;
    for (int i = 1; i <= N; ++i) {
        X[S++] = L[i];
        X[S++] = R[i]+1; // why +1? because the length is [L, R] include
    }
    sort(X, X+S);
    S = unique(X, X+S) - X;
    for (int i = 1; i <= N; ++i) { // discrete
        L[i] = lower_bound(X, X+S, L[i]) - X;
        R[i] = lower_bound(X, X+S, R[i]+1) - X;
    }

    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; ++i) {
        update(L[i], R[i], 1, 0, S-1, 1);
    }
    result = sum[1];
    for (int i = 1; i <= N; ++i) {
        update(L[i], R[i], -1, 0, S-1, 1);
        result = min(result, sum[1]);
        update(L[i], R[i], 1, 0, S-1, 1);
    }

}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        solve();
        cout << "Case #" << cases << ": " << result << endl;
    }
}
