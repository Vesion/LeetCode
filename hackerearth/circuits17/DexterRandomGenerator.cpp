#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// LCA ST-DP + Persistent trie

const int MAXN = 1e5+5;
const int MAXD = 20;
const int MAXL = 31;
vector<int> tree[MAXN];
int val[MAXN];
int trie[2*MAXN*MAXL], to[2*MAXN*MAXL][2], ptr, root[MAXN]; // for trie
int depth[MAXN], dp[MAXN][MAXD]; // for lca
int N, M;

int insert(int num, int dep, int pre) {
    int newroot = ptr++;
    int cur = newroot;
    for (int i = MAXL-1; i >= 0; --i) {
        int bit = (num>>i)&1;
        to[cur][bit^1] = to[pre][bit^1];
        to[cur][bit] = ptr++;
        pre = to[pre][bit];
        cur = to[cur][bit];
        trie[cur] = dep;
    }
    return newroot;
}

int query(int num, int dep, int root) {
    int cur = root;
    int res = 0;
    for (int i = MAXL-1; i >= 0; --i) {
        int bit = (num>>i)&1;
        if (to[cur][bit^1] && trie[to[cur][bit^1]] >= dep) {
            res = (res<<1) + 1;
            cur = to[cur][bit^1];
        } else {
            res = res<<1;
            cur = to[cur][bit];
        }
    }
    return res;
}

void dfs(int cur, int par) {
    depth[cur] = depth[par]+1;
    dp[cur][0] = par;
    for (int i = 1; i < MAXD; ++i) dp[cur][i] = dp[dp[cur][i-1]][i-1];
    root[cur] = insert(val[cur], depth[cur], root[par]);
    for (int& child : tree[cur]) {
        if (child == par) continue;
        dfs(child, cur);
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v]-depth[u];
    for (int i = 0; i < MAXD; ++i)
        if ((diff>>i) & 1) v = dp[v][i];
    if (u == v) return u;
    for (int i = MAXD-1; i >= 0; --i) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

int main() {
    ptr = 1;
    cin >> N >> M; 
    for (int i = 1; i <= N; ++i) cin >> val[i];
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0);
    while (M--) {
        int u, v; cin >> u >> v;
        int d = depth[lca(u, v)];
        int res = query(val[u], d, root[u]);
        res = max(res, query(val[u], d, root[v]));
        res = max(res, query(val[v], d, root[u]));
        res = max(res, query(val[v], d, root[v]));
        cout << res << endl;
    }
    return 0;
}
