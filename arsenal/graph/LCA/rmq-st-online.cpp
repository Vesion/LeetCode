#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Sparse Table, DP

const int MAXN = 1e5;
const int MAXD = 20;
vector<int> tree[MAXN];
int depth[MAXN];
int dp[MAXN][MAXD]; // dp[i][j] = the 2^j-th ancestor of node i (e.g. dp[3][0] is the direct parent of node 3)
int N, Q;

void dfs(int cur, int par) {
    depth[cur] = depth[par]+1;
    dp[cur][0] = par;
    for (int i = 1; i < MAXD; ++i) dp[cur][i] = dp[dp[cur][i-1]][i-1];
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
    cin >> N >> Q;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 0; i < Q; ++i) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
    
