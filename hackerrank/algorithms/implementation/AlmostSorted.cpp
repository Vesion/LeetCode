#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN], b[MAXN];
int n;
int l = -1, r = -1;

int solve() {
    sort(b, b+n);
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) { l = i; break; }
    for (int i = n-1; i >= 0; --i) if (a[i] != b[i]) { r = i; break; }
    bool s = true;
    for (int i = l+1; i <= r-1; ++i) if (a[i] != b[i]) { s = false; break; }
    if (s) return 1;
    s = true;
    for (int i = l; i <= r; ++i) if (a[i] != b[r-(i-l)]) { s = false; break; }
    if (s) return 2;
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    int res = solve();
    if (res == 1) cout << "yes\nswap " << l+1 << " " << r+1 << endl;
    else if (res == 2) cout << "yes\nreverse " << l+1 << " " << r+1 << endl;
    else cout << "no" << endl;
    return 0;
}
