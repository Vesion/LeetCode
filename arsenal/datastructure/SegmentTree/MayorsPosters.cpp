#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 10008;

struct Post {
    int left, right;
} posts[MAX];

int xs[MAX<<2], xn; // for discrete
int id[MAX<<4]; // every poster has a unique id or color
bool visit[MAX]; // record if has visited a poster
int ans;

void push_down(int i) {
    if (id[i]) {
        id[i*2] = id[i*2+1] = id[i];
        id[i] = 0;
    }
}

void update(int i, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        id[i] = v;
        return;
    }
    push_down(i);
    int mid = l + (r-l)/2;
    if (L <= mid) update(i*2, l, mid, L, R, v);
    if (R > mid) update(i*2+1, mid+1, r, L, R, v);
}

void query(int i, int l, int r) {
    if (id[i]) { // if this node has id, it means this interval has been covered by a post, so return
        if (!visit[id[i]]) {
            ++ans;
            visit[id[i]] = true;
        }
        return;
    }
    if (l == r) return;
    int mid = l + (r-l)/2;
    query(i*2, l, mid);
    query(i*2+1, mid+1, r);
}

int main() {
    int cases; 
    cin >> cases;
    while (cases--) {
        memset(id, 0, sizeof (id));  
        memset (visit, false, sizeof (visit));  
        xn = 1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &posts[i].left, &posts[i].right);
            xs[xn++] = posts[i].left;
            xs[xn++] = posts[i].right;
        }
        sort(xs+1, xs+xn);

        int m = 1;
        for (int i = 2; i <= xn; ++i)
            if (xs[i] != xs[i-1]) xs[++m] = xs[i];
        for (int i = m; i > 1; --i)
            if (xs[i] - xs[i-1] > 1) xs[++m] = xs[i] - 1;
        xn = m+1;
        sort(xs+1, xs+xn);

        for (int i = 1; i <= n; ++i) {
            int l = lower_bound(xs+1, xs+xn, posts[i].left) - xs;
            int r = lower_bound(xs+1, xs+xn, posts[i].right) - xs;
            update(1, 1, xn, l, r, i);
        }

        ans = 0;
        query(1, 1, xn);
        cout << ans << endl;
    }
    return 0;
}
