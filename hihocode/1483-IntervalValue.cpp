#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map> 
using namespace std;

using ll = long long;
const int MAXN = 200005;

ll a[MAXN];
ll n, k;
unordered_map<ll, ll> ma;

bool check(ll x) {
    ll count = 0, now = 0;
    unordered_map<ll, ll> m;
    int i = 0, j = 0;
    while (i < n) {
        now += m[a[i++]]++;
        while (now > x) now -= --m[a[j++]];
        count += i-j;
    }
    return count >= k;
}

int main() {
    int T; cin >> T; 
    while (T--) {
        cin >> n >> k;
        ma.clear();
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll left = 0, right = n*(n-1)/2;
        while (left <= right) {
            ll mid = left + (right-left)/2;
            if (check(mid)) right = mid-1;
            else left = mid+1;
        }
        cout << left << endl;
    }
    return 0;
}
