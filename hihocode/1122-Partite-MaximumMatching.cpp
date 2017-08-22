#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 1e3+5;
vector<int> g[MAXN];
int link[MAXN];
bool vis[MAXN];
int N, M;

bool dfs(int u) {
    for (int& v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (!link[v] || dfs(link[v])) {
                link[u] = v;
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M; 
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (!link[i]) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) ++res; // find augment path starting from u
        }
    }
    cout << res << endl;
    return 0;
}
