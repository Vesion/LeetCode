#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <unordered_map> 
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN], res[MAXN];
int parent[MAXN], root[MAXN];
int color[MAXN];
vector<int> tree[MAXN];
vector<pair<int,int>> query[MAXN];
int N, Q;

int findRoot(int i) {
    if (root[i] != i) root[i] = findRoot(root[i]);
    return root[i];
}

int calc(int u, int v, int lca) {
    int r = 0;
    int i = u;
    while (true) {
        r = max(r, a[i]^a[u]);
        r = max(r, a[i]^a[v]);
        if (i == lca) break;
        i = parent[i];
    }
    i = v;
    while (true) {
        r = max(r, a[i]^a[u]);
        r = max(r, a[i]^a[v]);
        if (i == lca) break;
        i = parent[i];
    }
    return r;
}

void dfs(int cur, int par) {
    color[cur] = 1;
    parent[cur] = par;
    if (!query[cur].empty()) {
        for (auto& p : query[cur]) {
            int other = p.first;
            if (color[other] == 1) {
                res[p.second] = calc(cur, other, other);
            } else if (color[other] == 2) {
                res[p.second] = calc(cur, other, findRoot(other));
            }
        }
    }
    for (int& child : tree[cur]) {
        if (child != par) {
            dfs(child, cur);
        }
    }
    color[cur] = 2;
    root[cur] = par;
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= N-1; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 0; i < Q; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        query[u].push_back({v, i});
        query[v].push_back({u, i});
    }
    for (int i = 0; i <= N; ++i) parent[i] = -1;
    for (int i = 0; i <= N; ++i) root[i] = i;
    dfs(1, 0);
    for (int i = 0; i < Q; ++i) printf("%d\n", res[i]);
    return 0;
}
