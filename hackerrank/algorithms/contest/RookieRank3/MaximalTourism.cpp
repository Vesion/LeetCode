#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int root[MAXN];
int cnt[MAXN];
int n, m;

int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
}


int main() {
    scanf("%d %d", &n, &m); 
    for (int i = 1; i <= n; ++i) root[i] = i;
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        int ra = findRoot(a), rb = findRoot(b);
        if (ra != rb) root[ra] = rb;
    }
    for (int i = 1; i <= n; ++i) findRoot(i);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[root[i]]++;   
        res = max(res, cnt[root[i]]);
    }
    printf("%d\n", res);
    return 0;
}
