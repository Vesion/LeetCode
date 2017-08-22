#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

using ll = unsigned long long;
ll a[55];
bool f[100];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        ll x = a[i]^a[i+1];
        for (int j = 59; j >= 0; --j) {
            if (x & (1ULL<<j)) {
                f[j] = true;
                break;
            }
        }
    }
    ll res = 1;
    for (int i = 0; i <= 59; ++i) if (!f[i]) res <<= 1;
    cout << res << endl;
    return 0;
}
