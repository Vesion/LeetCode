#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

const int MAX = 100005;

struct Build {
    ll A, B, H;
    bool operator<(const Build& b) const { return H < b.H; }
} b[MAX];

ll height[MAX*4]; // lower height will be covered by higher height
ll s[MAX], sn = 0;
ll sum = 0;

void push_down(int i) {
    if (height[i]) {
        height[i*2] = height[i*2+1] = height[i];
        height[i] = 0;
    }
}

void update(int i, int l, int r, int L, int R, ll v) {
    if (L <= l && r <= R) {
        height[i] = v;
        return;
    }
    push_down(i);
    int mid = (l+r)/2;
    if (L <= mid) update(i*2, l, mid, L, R, v);
    if (R > mid) update(i*2+1, mid+1, r, L, R, v);
}

void query(int i, int l, int r) {
    if (l == r) {
        sum += height[i] * (s[l+1]-s[l]);
        return;
    }
    push_down(i);
    int mid = (l+r)/2;
    query(i*2, l, mid);
    query(i*2+1, mid+1, r);
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld%lld",&b[i].A, &b[i].B, &b[i].H);
        s[++sn] = b[i].A;
        s[++sn] = b[i].B;
    }
    sort(s+1, s+sn+1);
    sn = unique(s+1, s+sn+1) - s - 1;

    memset(height, 0, sizeof height);
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i) {
        int l = lower_bound(s+1, s+sn+1, b[i].A) - s;
        int r = lower_bound(s+1, s+sn+1, b[i].B) - s;
        update(1, 1, sn, l, r-1, b[i].H);
    }

    query(1, 1, sn);
    cout << sum << endl;

    return 0;
}
