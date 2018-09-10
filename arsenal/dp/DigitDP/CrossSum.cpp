#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 
using namespace std;

// http://hihocoder.com/problemset/problem/1033

using ll = long long;
const ll MOD = 1000000007;
ll l, r, k;
ll base[20], digit[20];

struct Node {
    ll s, n;
} dp[20][201];

Node dfs(int pos, int start, int target, bool limit) {
    Node res;
    res.s = res.n = 0;
    if (pos == 0) {
        if (target == 100) res.n = 1;
        return res;
    }
    if (!limit && dp[pos][target].n != -1) return dp[pos][target];
    int sign = ((start-pos)&1) ? -1 : 1;
    int lower = pos == start ? 1 : 0;
    int upper = limit ? digit[pos] : 9;
    for (int i = lower; i <= upper; ++i) {
        Node t = dfs(pos-1, start, target-sign*i, limit && i == digit[pos]);
        if (t.n) {
            res.n += t.n;
            res.s = (res.s + t.n%MOD * i * base[pos]%MOD + t.s%MOD) % MOD;
        }
    }
    if (!limit) dp[pos][target] = res;
    return res;
}


ll solve(ll x) {
    ll n = 1, res = 0;
    while (x) {
        digit[n++] = x % 10;
        x /= 10;
    }
    for (int i = 1; i < n; ++i) {
        memset(dp, -1, sizeof dp);
        res = (res + dfs(i, i, k+100, i == n-1).s) % MOD;
    }
    return res;
}

int main() {
    cin >> l >> r >> k; 
    base[1] = 1;
    for (int i = 2; i < 20; ++i) base[i] = base[i-1]*10 % MOD;
    cout << (solve(r) - solve(l-1) + MOD) % MOD << endl;
    return 0;
}
