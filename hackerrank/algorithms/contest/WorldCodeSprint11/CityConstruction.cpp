#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 5e4+5;
vector<int> tree[MAXN];
bool vis[MAXN];
int N, M, Q;

bool dfs(int u, int v) {
    if (u == v) return true;
    vis[u] = true;
    for (int& c : tree[u]) if (!vis[c] && dfs(c, v)) return true;
    return false;
}

int main() {
    cin >> N >> M; 
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
    }
    cin >> Q;
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            if (v == 1) tree[++N].push_back(u);
            else tree[u].push_back(++N);
        } else {
            memset(vis, 0, sizeof vis);
            bool r = dfs(u, v);
            cout << (r ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
