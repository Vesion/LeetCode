#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.empty()) return true;

        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses);
        for (auto& p : prerequisites) {
            graph[p.first].push_back(p.second);
            indegrees[p.second]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indegrees[i] == 0) q.push(i);
        if (q.empty()) return false;

        while (!q.empty()) {
            int t = q.front(); q.pop();
            numCourses--; // count the number of nodes haven't been visited
            for (int nbr : graph[t])
                if (--indegrees[nbr] == 0) q.push(nbr);
            if (q.empty() && numCourses != 0) return false; // if some nodes haven't been visited, but cannot be enqued, there exists a cycle
        }
        return true;
    }
};


// Solution 2 : DFS
class Solution2 {
public:
    vector<vector<int>> g;
    vector<int> vis; // 0 non-visited, 1 visiting, 2 visited
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        g.resize(n);
        vis.resize(n, false);
        for (const auto& q : prerequisites) {
            g[q[1]].push_back(q[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 2) continue;
            if (!dfs(i)) return false;
        }
        return true;
    }

    bool dfs(int i) {
        if (vis[i] == 2) return true;
        vis[i] = 1;
        for (int j : g[i]) {
            if (vis[j] == 1 || !dfs(j)) return false;
        }
        vis[i] = 2;
        return true;
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> p = {{1,0}};
    cout << s.canFinish(2, p) << endl;
    return 0;
}

