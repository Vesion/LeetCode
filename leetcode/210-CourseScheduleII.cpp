#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p.second].push_back(p.first);
            indegrees[p.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indegrees[i] == 0) q.push(i);

        vector<int> res;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int& nbr : graph[t]) {
                if (--indegrees[nbr] == 0) q.push(nbr);
            }
        }
        if ((int)res.size() != numCourses) return {};
        return res;
    }
};


// Solution 2 : DFS
class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis, onpath;
    vector<int> res;

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        g.resize(n);
        for (const auto& p : prerequisites) g[p[1]].push_back(p[0]);

        vis.resize(n, false);
        onpath.resize(n, false);
        for (int i = 0; i < n; ++i)
            if (cycle(i)) return {};
        reverse(res.begin(), res.end());
        return res;
    }

    bool cycle(int i) {
        if (vis[i]) return false;
        vis[i] = onpath[i] = true;
        for (int j : g[i]) {
            if (onpath[j] || cycle(j)) return true;
        }
        onpath[i] = false;
        res.push_back(i);
        return false;
    }
};


int main() {
    Solution_2 s;
    vector<pair<int,int>> p = {{1,0}};
    s.findOrder(2, p);
    return 0;
}

