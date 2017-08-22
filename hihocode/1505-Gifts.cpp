#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set> 
using namespace std;

using ll = long long;
const int MAX = 1000005;

int a[1005];
int cnt[MAX], sum[2*MAX];
unordered_set<int> s;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            sum[a[i]+a[j]]++;
    
    ll res = 0;
    for (int i = 0; i < 2*MAX; ++i) res += (ll)sum[i]*(sum[i]-1)/2;
    for (int i = 0; i < n; ++i) {
        for (int x : s) {
            ll c = cnt[x];
            if (x != a[i]) res -= c*(c-1)/2;
            else res -= (c-1)*(c-2)/2;
        }
    }
    cout << res*2 << endl;
    return 0;
}
