#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 50005;
int a[MAXN];
int b[MAXN];
int n, q;
int L, R, I, J;
int ll, rr, ii, jj;
int ans = 0;

void foo() {
    ll = 1 + ((ans ^ L) % n);
    rr = 1 + ((ans ^ R) % n);
    if(ll > rr) swap(ll, rr);
    ii = 1 + ((I ^ ans) % (rr - ll + 1));
    jj = 1 + ((J ^ ans) % (rr - ll + 1));
    if(ii > jj) swap(ii, jj);
}

void solve() {
    int k = 1;
    for (int i = ll; i <= rr; ++i) b[k++] = a[i];
    sort(b+1, b+k);
    ans = 0;
    for (int i = ii; i <= jj; ++i) ans ^= b[i];
}

int main() {
    scanf("%d %d", &n, &q); 
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < q; ++i) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int p, x; scanf("%d %d", &p, &x);
            a[p] = x;
        } else {
            scanf("%d %d %d %d", &L, &R, &I, &J);
            foo();
            solve();
            printf("%d\n", ans);
        }
    }
    return 0;
}
