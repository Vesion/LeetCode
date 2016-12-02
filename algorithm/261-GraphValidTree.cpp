#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : DFS (BFS is similar to DFS)
class Solution_1 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n+1);
        for (auto& p : edges) {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        vector<bool> visited(n, false);
        return (int)edges.size() == n-1 && !hasCycle(0, -1, visited, graph);
    }
    
    bool hasCycle(int cur, int parent, vector<bool>& visited, vector<vector<int>>& graph) {
        if (visited[cur]) return true;
        visited[cur] = true;
        for (int nbr : graph[cur]) {
            if (nbr == parent) continue;
            if (hasCycle(nbr, cur, visited, graph)) return true;
        }
        return false;
    }
};


// Solution 2 : Union Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;

        for (auto& p : edges) {
            int r1 = findRoot(root, p.first);
            int r2 = findRoot(root, p.second);
            if (r1 == r2) return false; // has cycle
            root[r1] = r2;
        }
        // no cycle
        return (int)edges.size() == n-1; // connected
    }

    int findRoot(vector<int>& root, int cur) {
        if (root[cur] != cur) root[cur] = findRoot(root, root[cur]);
        return root[cur];
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> e = {{0,1}, {1,2}, {3,4}};
    cout << s.validTree(5, e) << endl;
    return 0;
}
