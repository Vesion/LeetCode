#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Brute force, O(N^2), TLE
class Solution0 {
public:
    vector<unordered_map<int,int>> g;
    vector<bool> vis;

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        g.resize(n);
        for (const auto& e : edgeList) {
            int i = e[0], j = e[1], d = e[2];
            if (g[i].count(j)) g[i][j] = min(g[i][j], d);
            else g[i][j] = d;
            if (g[j].count(i)) g[j][i] = min(g[j][i], d);
            else g[j][i] = d;
        }
        vis = vector<bool>(n);

        int m = queries.size();
        vector<bool> res(m);
        for (int i = 0; i < m; ++i) {
            fill(vis.begin(), vis.end(), false);
            const auto& q = queries[i];
            res[i] = dfs(q[0], q[1], q[2]);
        }
        return res;
    }

    bool dfs(int i, int t, int limit) {
        if (i == t) return true;
        vis[i] = true;
        for (const auto& p : g[i]) {
            int j = p.first, d = p.second;
            if (vis[j]) continue;
            if (d >= limit) continue;
            if (dfs(j, t, limit)) return true;
        }
        return false;
    }
};


// Sort and union-find
class Solution {
public:
    vector<int> root;
    int find(int x) {
        if (x != root[x]) root[x] = find(root[x]);
        return root[x];
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) root[rx] = ry;
    }
    bool linked(int x, int y) {
        return find(x) == find(y);
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& es, vector<vector<int>>& qs) {
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        sort(es.begin(), es.end(),
             [](const vector<int>& e1, const vector<int>& e2) {
                 return e1[2] < e2[2];
             });
        int m = qs.size();
        vector<int> qid(m, 0);
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(),
             [&qs](int i, int j) {
                 return qs[i][2] < qs[j][2];
             });

        vector<bool> res(m);
        int s = 0;
        for (int id : qid) {
            const auto& q = qs[id];
            int i = q[0], j = q[1], limit = q[2];
            while (s < es.size() && es[s][2] < limit) {
                link(es[s][0], es[s][1]);
                ++s;
            }
            res[id] = linked(i, j);
        }
        return res;
    }
};

int main() {

}
