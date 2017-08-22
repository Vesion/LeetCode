#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100005;
int nums[MAX];
int sums[4*MAX], lazy[4*MAX];
int N, Q;

void push_up(int i) {
    sums[i] = sums[i*2] + sums[i*2+1];
}

void push_down(int i, int l, int r) {
    if (lazy[i]) {
        lazy[i*2] = lazy[i*2+1] = lazy[i];
        int mid = l + (r-l)/2;
        sums[i*2] = lazy[i] * (mid-l+1);
        sums[i*2+1] = lazy[i] * (r-mid);
        lazy[i] = 0;
    }
}

void build(int i, int l, int r) {
    if (l == r) {
        sums[i] = nums[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push_up(i);
}

void update(int i, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        sums[i] = v*(r-l+1);
        lazy[i] = v;
        return;
    }
    push_down(i, l, r);
    int mid = l + (r-l)/2;
    if (L <= mid) update(i*2, l, mid, L, R, v);
    if (R > mid) update(i*2+1, mid+1, r, L, R, v);
    push_up(i);
}

int query(int i, int l, int r, int L, int R) {
    if (L <= l && r <= R) return sums[i];
    push_down(i, l, r);
    int res = 0;
    int mid = l + (r-l)/2;
    if (L <= mid) res += query(i*2, l, mid, L, R);
    if (R > mid) res += query(i*2+1, mid+1, r, L, R);
    return res;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &nums[i]);
    build(1, 1, N);

    scanf("%d", &Q);
    while (Q--) {
        int op, l, r, v; scanf("%d %d %d", &op, &l, &r);
        if (op == 0) printf("%d\n", query(1, 1, N, l, r));
        else { scanf("%d", &v); update(1, 1, N, l, r, v); }
    }
    return 0;
}
