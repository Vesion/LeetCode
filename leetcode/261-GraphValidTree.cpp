#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return true;
        if ((int)edges.size() != n-1) return false;
        vector<vector<int>> graph(n);
        vector<int> indegrees(n, 0);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
            indegrees[e.first]++;
            indegrees[e.second]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (indegrees[i] == 1) q.push(i);
        int count = 0;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            ++count;
            for (int& nbr : graph[t]) if (--indegrees[nbr] == 1) q.push(nbr);
        }
        return count == n;
    }
};


// Solution 2 : DFS
class Solution2 {
public:
    vector<vector<int>> g;
    vector<int> vis;
    bool validTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.resize(n, 0);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if (!dfs(0, -1)) return false;
        for (int i = 0; i < n; ++i) if (vis[i] != 2) return false;
        return true;
    }
    bool dfs(int i, int p) {
        if (vis[i] == 2) return true;
        vis[i] = 1;
        for (int j : g[i]) {
            if (j == p) continue;
            if (vis[j] == 1 || !dfs(j, i)) return false;
        }
        vis[i] = 2;
        return true;
    }
};


// Solution 3 : Union Find
class Solution3 {
public:
    vector<int> root;
    int find(int x) {
        return x == root[x] ? x : root[x] = find(root[x]);
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        for (const auto& e : edges) {
            int rx = find(e[0]), ry = find(e[1]);
            if (rx == ry) return false;
            root[rx] = ry;
            --n;
        }
        return n == 1;
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> e = {{0,1}, {1,2}, {3,4}};
    cout << s.validTree(5, e) << endl;
    return 0;
}
