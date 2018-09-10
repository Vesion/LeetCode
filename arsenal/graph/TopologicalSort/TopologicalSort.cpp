#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <map> 
#include <queue> 
using namespace std;

// Topological Sort ususallly occurs in schedule-like problems
// We can use either the O(V+E) DFS or BFS to perform Topological Sort for DAG.

const int MAXN = 100;
int n;
vector<int> g[MAXN]; // graph

// Solution 1 : BFS (Kahn's algorithm)

int ind[MAXN]; // indegrees

vector<int> bfs() {
    memset(ind, 0, sizeof ind);
    for (int i = 0; i < n; ++i) for (int& c : g[i]) ++ind[c];
    queue<int> q;
    for (int i = 0; i < n; ++i) if (ind[i] == 0) q.push(i);

    vector<int> res;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        res.push_back(t);
        for (int& c : g[t]) {
            if (--ind[c] == 0) q.push(c);
        }
    }
    if ((int)res.size() != n) return {}; // has cycle
    return res;
}


// Solution 2 : DFS

int visit[MAXN], onpath[MAXN];

bool hasCycle(int cur, vector<int>& res) {
    if (visit[cur]) return false;
    visit[cur] = onpath[cur] = true;
    for (int& child : g[cur]) {
        if (onpath[child] || hasCycle(child, res)) return true;
    }
    onpath[cur] = false;
    res.push_back(cur);
    return false;
}

vector<int> dfs() {
    memset(visit, 0, sizeof visit);
    memset(onpath, 0, sizeof onpath);
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (!visit[i] && hasCycle(i, res)) return {}; // has cycle
    }
    reverse(res.begin(), res.end());
    return res;
}


int main() {
    n = 4;
    g[0].push_back(1);
    g[1].push_back(2);
    g[2].push_back(3);
    g[3].push_back(1);
    auto r = dfs();
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
