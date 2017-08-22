#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <unordered_map> 
using namespace std;

using ll = long long;
const ll MAXN = 1e7+5;
int phi[MAXN];

void get_phi() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] -= phi[j]/i;
            }
        }
    }
}

ll pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll f(ll x, ll k, ll m) {
    if (k == 0) return 1;
    if (m == 1) return 0;
    return pow(x, f(x, k-1, phi[m]), m);
}

int main() {
    get_phi();
    int t; scanf("%d", &t);
    while (t--) {
        ll x, k, m;
        scanf("%lld %lld %lld", &x, &k, &m);
        printf("%lld\n", f(x, k, m));
    }
    return 0;
}
