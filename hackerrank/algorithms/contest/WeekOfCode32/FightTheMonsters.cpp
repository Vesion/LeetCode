#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <queue> 
using namespace std;
using ll = long long;

const int MAXN = 1e5+5;
ll h[MAXN];
ll n, t, hit;

int main() {
    cin >> n >> hit >> t;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h, h+n);
    int res = 0;
    while (t--) {
        h[res] -= hit;
        if (h[res] <= 0) ++res;
        if (res == n) break;
    }
    cout << res << endl;
    return 0;
}
