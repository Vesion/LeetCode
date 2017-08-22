#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN];
int r, n;

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) r += 2;
        else r -= 1;
        if (i < n && r <= 0) {
            cout << "No " << i << endl;
            return;
        }
    }
    cout << "Yes " << r << endl;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> r >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        solve();
    }
    return 0;
}
