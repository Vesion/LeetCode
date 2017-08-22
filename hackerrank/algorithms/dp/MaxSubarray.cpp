#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN];
int N;
int r1, r2;

void solve() {
    r1 = INT_MIN, r2 = 0;
    int t = 0, maxa = INT_MIN;
    for (int i = 0; i < N; ++i) {
        if (a[i] > 0) r2 += a[i];
        maxa = max(maxa, a[i]);
        t = max(t+a[i], a[i]);
        r1 = max(r1, t);
    }
    if (r2 == 0) r2 = maxa;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> a[i];
        solve();
        cout << r1 << " " << r2 << endl;
    }
    return 0;
}
