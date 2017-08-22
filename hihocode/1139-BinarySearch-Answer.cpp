#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <queue> 
using namespace std;
using ll = long long;

const int MAXN = 1e4+5;
struct E {
    int v, w;
};
vector<E> g[MAXN];
bool vis[MAXN];
int N, K, M, T;

bool bfs(int m, int k) {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(1); vis[1] = true;
    while (!q.empty() && --k >= 0) {
        int len = q.size();
        while (len--) {
            int u = q.front(); q.pop();
            for (auto& e : g[u]) {
                if (!vis[e.v] && e.w <= m) {
                    if (e.v == T) return true;
                    q.push(e.v);
                    vis[e.v] = true;
                }
            }
        }
    }
    return false;
}

int solve(int l, int r) {
    if (T == 1) return 0;
    while (l <= r) {
        int mid = l+(r-l)/2;
        if (bfs(mid, K)) r = mid-1;
        else l = mid+1;
    }
    return l;
}

int main() {
    cin >> N >> M >> K >> T;
    int l = INT_MAX, r = 0;
    for (int i = 0; i < M; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        l = min(l, w), r = max(r, w);
    }
    cout << solve(l, r) << endl;
    return 0;
}
