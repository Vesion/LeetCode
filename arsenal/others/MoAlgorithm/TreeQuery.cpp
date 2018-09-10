#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// http://www.spoj.com/problems/COT2/
// Problem: Given a tree, each node has a value, for each query (u, v), count the number of unique values of path u~v

const int MAXN = 1e5;
const int MAXD = 20;
vector<int> tree[MAXN];
int val[MAXN], unq[MAXN];
int depth[MAXN], dp[MAXN][MAXD];
int t[2*MAXN], tc = 0;
int st[MAXN], ed[MAXN];
int blocks;
struct Query {
    int id, l, r, lca;
    bool operator< (const Query& other) {
        if (l/blocks == other.l/blocks) return r < other.r;
        return l/blocks < other.l/blocks;
    }
} queries[MAXN];
int visit[MAXN], occur[MAXN];
int res[MAXN], now = 0;
int N, Q;

void dfs(int cur, int par) {
    t[tc] = cur;
    st[cur] = tc++;
    depth[cur] = depth[par]+1;
    dp[cur][0] = par;
    for (int i = 1; i < MAXD; ++i) dp[cur][i] = dp[dp[cur][i-1]][i-1];
    for (int& child : tree[cur]) {
        if (child == par) continue;
        dfs(child, cur);
    }
    t[tc] = cur;
    ed[cur] = tc++;
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v]-depth[u];
    for (int i = 0; i < MAXD; ++i)
        if ((diff>>i)&1) v = dp[v][i];
    if (u == v) return u;
    for (int i = MAXD-1; i >= 0; --i) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

void calc(int x) {
    if (visit[x] && --occur[val[x]] == 0) --now;
    else if (!visit[x] && occur[val[x]]++ == 0) ++now;
    visit[x] = !visit[x];
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> val[i];
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // discretization
    for (int i = 1; i <= N; ++i) unq[i] = val[i];
    int k = unique(unq+1, unq+N+1)-unq-1;
    for (int i = 1; i <= N; ++i) val[i] = lower_bound(unq+1, unq+k+1, val[i])-unq;

    // convert a tree into an array, and get lca
    dfs(1, 1);

    // Mo's Algo
    blocks = sqrt(N+0.5);    
    for (int i = 0; i < Q; ++i) {
        int u, v; cin >> u >> v;
        if (st[u] > st[v]) swap(u, v);
        queries[i].lca = lca(u, v);
        if (queries[i].lca == u) queries[i].l = st[u], queries[i].r = st[v];
        else queries[i].l = ed[u], queries[i].r = st[v];
        queries[i].id = i;
    }
    sort(queries, queries+Q);
    
    int l = queries[0].l, r = queries[0].l-1;
    for (int i = 0; i < Q; ++i) {
        while (l < queries[i].l) calc(t[l++]);
        while (r > queries[i].r) calc(t[r--]);
        while (l > queries[i].l) calc(t[--l]);
        while (r < queries[i].r) calc(t[++r]);
        int u = t[l];
        if (queries[i].lca != u) calc(queries[i].lca);
        res[i] = now;
        if (queries[i].lca != u) calc(queries[i].lca);
    }
    for (int i = 0; i < Q; ++i) cout << res[i] << endl;
    return 0;
}
