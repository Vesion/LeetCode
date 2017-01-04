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
        if ((int)edges.size() != n-1) return {}; // it's not a tree
        if (n == 1) return {0}; // single node, it's the root
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        vector<int> indegrees(n, 0);
        for (auto& nodes : graph) {
            for (int& node : nodes) indegrees[node]++;
        }
        
        vector<int> cur, next;
        for (int i = 0; i < n; ++i) if (indegrees[i] == 1) cur.push_back(i);
        while (!cur.empty()) {
            for (int& node : cur) {
                for (int& nbr : graph[node]) {
                    if (--indegrees[nbr] == 1) next.push_back(nbr);
                }
            }
            if (!next.empty()) { cur = next; next.clear(); }
            else break;
        }
        return cur;
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
