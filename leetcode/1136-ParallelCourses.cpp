#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// Topological sort

// BFS
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> g(n+1);
        vector<int> ind(n+1, 0);
        for (const auto& r : relations) {
            g[r[0]].push_back(r[1]);
            ++ind[r[1]];
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) if (ind[i] == 0) q.push(i);
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int i = q.front(); q.pop();
                for (int j : g[i]) {
                    if (--ind[j] == 0) q.push(j);
                }
            }
            ++res;
        }
        for (int i = 1; i <= n; ++i) if (ind[i]) return -1;
        return res;
    }
};

// DFS
class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> depth;
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        g.resize(n+1);
        vis.resize(n+1, 0);
        depth.resize(n+1, 1);
        for (const auto& r : relations) {
            g[r[0]].push_back(r[1]);
        }

        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0 && !dfs(i)) return -1;
        }
        return *max_element(depth.begin(), depth.end());
    }

    bool dfs(int i) {
        if (vis[i] == 2) return true;
        vis[i] = 1;
        for (int j : g[i]) {
            if (vis[j] == 1 || !dfs(j)) return false;
            depth[i] = max(depth[i], depth[j]+1);
        }
        vis[i] = 2;
        return true;
    }
};

int main() {

}