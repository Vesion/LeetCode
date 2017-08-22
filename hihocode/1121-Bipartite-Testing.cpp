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
vector<int> g[MAXN];
int color[MAXN];
int N, M;

bool bfs(int s) {
    queue<int> q;
    q.push(s); color[s] = 0;
    while (!q.empty()) {
        int t = q.front(); q.pop(); 
        for (int& nbr : g[t]) {
            if (color[nbr] == -1) { q.push(nbr); color[nbr] = 1-color[t]; }
            else if (color[nbr] == color[t]) return false;
        }
    }
    return true;
}

int main() {
    int T; cin >> T; while (T--) {
        cin >> N >> M;
        for (int i = 0; i < MAXN; ++i) g[i].clear();
        memset(color, -1, sizeof color);
        for (int i = 0; i < M; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool r = true;
        for (int i = 1; i <= N; ++i) {
            if (color[i] == -1) r &= bfs(i);
        }
        cout << (r ? "Correct" : "Wrong") << endl;
    }
    return 0;
}
