#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// BFS, delete leaves level by level
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegrees(n, 0);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
            indegrees[e.first]++;
            indegrees[e.second]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (indegrees[i] == 1) q.push(i);

        vector<int> res;
        while (!q.empty()) {
            int len = q.size();
            vector<int> leaves;
            while (len--) {
                int t = q.front(); q.pop();
                leaves.push_back(t);
                for (int& nbr : graph[t]) if (--indegrees[nbr] == 1) q.push(nbr);
            }
            res = leaves;
        }
        return res;
    }
};


// Solution 2 : find longest path
// The final root (or two roots) must be the middle point of the longest path in the graph(tree)
// So, we pick any one point x, do dfs/bfs to find y which is farthest from x,
// then from y, do dfs/bfs to find z which is farthest from y,
// as a result, our target root is the middle point of the path y-z


int main() {
    Solution s;
    vector<pair<int,int>> e = {};
    auto r = s.findMinHeightTrees(1, e);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
