#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

using ll = long long;
const int MAX = 100010;

int N, M;
vector<pair<ll, ll>> g[MAX];
ll level[MAX];
ll nodes[MAX]; // nodes[i] means the number of nodes in subtree i included
ll len[MAX]; // the edge weight between i and its parent
ll res;

void dfs(ll root, ll parent) {
    nodes[root] = 1;
    for (auto& p : g[root]) {
        ll child = p.first;
        if (child != parent) {
            level[child] = level[root] + 1;
            len[child] = p.second;
            dfs(child, root);
            nodes[root] += nodes[child];
        }
    }
    res += len[root] * (nodes[root] * (N-nodes[root]));
}


int main() {
    cin >> N >> M;
    ll u, v, k;
    for (int i = 0; i < N-1; ++i) {
        cin >> u >> v >> k;
        g[u].push_back({v, k});
        g[v].push_back({u, k});
    }
    dfs(1, 0);

    string act;
    while (M--) {
        cin >> act;
        if (act == "QUERY")
            cout << res << endl;
        else {
            cin >> u >> v >> k;
            if (level[u] > level[v]) swap(u, v);
            res += (k-len[v]) * (nodes[v] * (N-nodes[v]));
            len[v] = k;
        }
    }

    return 0;
}
