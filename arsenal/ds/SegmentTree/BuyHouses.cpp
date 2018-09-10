#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// https://hihocoder.com/problemset/problem/1080
// mix two types of modification

const int MAX = 100005;
int nums[MAX];
int sums[4*MAX], lazy_add[4*MAX], lazy_set[4*MAX];
int N, M;

void push_up(int i) {
    sums[i] = sums[i*2] + sums[i*2+1];
}

void push_down(int i, int l, int r) {
    int mid = l+(r-l)/2;
    if (lazy_set[i]) {
        lazy_set[i*2] = lazy_set[i*2+1] = lazy_set[i];
        lazy_add[i*2] = lazy_add[i*2+1] = 0; // release childs' lazy_add
        sums[i*2] = lazy_set[i]*(mid-l+1);
        sums[i*2+1] = lazy_set[i]*(r-mid);
        lazy_set[i] = 0;
    }
    if (lazy_add[i]) {
        lazy_add[i*2] += lazy_add[i];
        lazy_add[i*2+1] += lazy_add[i];
        sums[i*2] += lazy_add[i]*(mid-l+1);
        sums[i*2+1] += lazy_add[i]*(r-mid);
        lazy_add[i] = 0;
    }
}

void build(int i, int l, int r) {
    if (l == r) {
        sums[i] = nums[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push_up(i);
}

void update(int i, int l, int r, int L, int R, int v, int op) {
    if (r > l) push_down(i, l, r); // push down before everything
    if (L <= l && r <= R) {
        if (op == 0) {
            lazy_add[i] += v;
            sums[i] += (r-l+1)*v;
        } else {
            lazy_set[i] = v;
            sums[i] = (r-l+1)*v;
        }
        return;
    }
    int mid = l+(r-l)/2;
    if (L <= mid) update(i*2, l, mid, L, R, v, op);
    if (R > mid) update(i*2+1, mid+1, r, L, R, v, op);
    push_up(i);
}

int main() {
    cin >> N >> M;
    ++N;
    for (int i = 1; i <= N; ++i) cin >> nums[i];
    build(1, 1, N);
    while (M--) {
        int op, l, r, v;
        cin >> op >> l >> r >> v;
        update(1, 1, N, l+1, r+1, v, op);
        cout << sums[1] << endl;
    }
    return 0;
}

