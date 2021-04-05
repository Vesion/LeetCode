#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

// Introduction:
//      Modui Algorithm, proposed by MoTao,
//      an offline algorithm used to deal with interval query problems without modification.
//      http://www.cnblogs.com/hzf-sbit/p/4056874.html
//      https://www.hackerearth.com/practice/notes/mos-algorithm
//
// e.g.
//      http://hihocoder.com/problemset/problem/1488

using ll = long long;

const int MAX = 20005;
int a[MAX], n, m, block;
ll bit1[MAX], bit2[MAX], res[MAX], now;
struct Q {
    int l, r, id;
} query[MAX];

bool cmp(const Q& q1, const Q& q2) {
    if (q1.l/block == q2.l/block) return q1.r < q2.r;
    return q1.l/block < q2.l/block;
}

void add(ll* bit, int i, int v) {
    for (; i < MAX; i += (i&-i)) bit[i] += v;
}

ll sum(ll* bit, int i) {
    ll r = 0;
    for (; i > 0; i -= (i&-i)) r += bit[i];
    return r;
}

void addx(int x) {
    now += sum(bit1, x) + x + x*(sum(bit2, MAX-1)-sum(bit2, x));
    add(bit1, x, x);
    add(bit2, x, 1);
}

void subx(int x) {
    add(bit1, x, -x);
    add(bit2, x, -1);
    now -= sum(bit1, x) + x + x*(sum(bit2, MAX-1)-sum(bit2, x));
}

int main() {
    int T; cin >> T;
    while (T--) {
        memset(bit1, 0, sizeof bit1);
        memset(bit2, 0, sizeof bit2);
        now = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) {
            cin >> query[i].l >> query[i].r;
            query[i].id = i;
        }
        block = sqrt(n+0.5);
        sort(query+1, query+1+m, cmp);

        int l = 1, r = 0;
        for (int i = 1; i <= m; ++i) {
            while (l > query[i].l) addx(a[--l]);
            while (r < query[i].r) addx(a[++r]);
            while (l < query[i].l) subx(a[l++]);
            while (r > query[i].r) subx(a[r--]);
            res[query[i].id] = now;
        }
        for (int i = 1; i <= m; ++i) cout << res[i] << endl;
    }
    return 0;
}


