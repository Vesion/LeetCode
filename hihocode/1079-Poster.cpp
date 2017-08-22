#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100005;
int a[MAX], b[MAX], x[2*MAX];
int color[8*MAX], visit[MAX];
int N, L;

void push_down(int i) {
    if (color[i]) {
        color[i*2] = color[i*2+1] = color[i];
        color[i] = 0;
    }
}

void update(int i, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        color[i] = v;
        return;
    }
    push_down(i);
    int mid = l + (r-l)/2;
    if (L < mid) update(i*2, l, mid, L, R, v);
    if (R > mid) update(i*2+1, mid, r, L, R, v);
}

void query(int i, int l, int r) {
    if (color[i]) {
        visit[color[i]] = 1;
        return;
    }
    if (l+1 == r) return;
    int mid = l + (r-l)/2;
    query(i*2, l, mid);
    query(i*2+1, mid, r);
}

int main() {
    scanf("%d %d", &N, &L); 
    int M = 1;
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        x[M++] = a[i]; x[M++] = b[i];
    }
    sort(x+1, x+M);

    // unique
    int m = 1;
    for (int i = 2; i <= M; ++i)
        if (x[i] != x[i-1]) x[++m] = x[i];
    // fix the bug someone posted
    for (int i = m; i > 1; --i)
        if (x[i] - x[i-1] > 1) x[++m] = x[i] - 1;
    M = m+1;
    sort(x+1, x+M);

    for (int i = 1; i <= N; ++i) {
        int l = lower_bound(x+1, x+M, a[i])-x;
        int r = lower_bound(x+1, x+M, b[i])-x;
        update(1, 1, M, l, r, i);
    }

    query(1, 1, M);
    int res = 0;
    for (int i = 1; i <= N; ++i) if (visit[i]) ++res;
    printf("%d\n", res);
    return 0;
}
