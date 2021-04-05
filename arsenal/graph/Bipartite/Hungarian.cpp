#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;

// Maximum Matching of Bipartite Graph
// Hungarian Algorithm, O(VE)
// https://blog.nowcoder.net/n/0e9a713d93f54bc79739588e928f091a
// https://www.jianshu.com/p/ee4e0cc72776
//
// Applications: if the number of maximum matchings is M, then
//      The Minimum Vertex Cover = M
//      The Maximum Independent Set = N-M

const int MAXN = 1e3+5;
vector<int> g[MAXN];  // graph, 1 to N
int link[MAXN];  // link[i] is the node matched with i
bool vis[MAXN];  // vis[i] is whether i has been visited
int N, M;

bool dfs(int u) {
    for (int& v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            // if link[v] is 0, it means v hasn't been matched, just link it
            // or try to recursively find augment path starting from v
            if (!link[v] || dfs(link[v])) {
                link[u] = v;
                link[v] = u;
                return true;
            }
        }
    }
    return false; // no augment path found
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = 0;  // maximum edges we want
    for (int i = 1; i <= N; ++i) {  // try to find an augment path in each iteration
        if (!link[i]) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) ++res; // find augment path starting from i
        }
    }
    cout << res << endl;
    return 0;
}

