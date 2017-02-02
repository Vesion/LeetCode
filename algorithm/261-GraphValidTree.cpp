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
class Solution_2 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if ((int)edges.size() != n-1) return false;
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        if (hasCycle(0, -1, graph, visited)) return false; // detect cycle
        for (int i = 0; i < n; ++i) if (!visited[i]) return false; // check if all nodes have been visited
        return true;
    }
    
    bool hasCycle(int cur, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
        if (visited[cur]) return true;
        visited[cur] = true;
        for (int& nbr : graph[cur]) {
            if (nbr != parent) {
                if (hasCycle(nbr, cur, graph, visited)) return true;
            }
        }
        return false;
    }
};


// Solution 3 : Union Find
class Solution_3 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if ((int)edges.size() != n-1) return false;
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);
        for (auto& e : edges) {
            int ri = findRoot(e.first, root), rj = findRoot(e.second, root);
            if (ri == rj) return false;
            root[ri] = rj;
        }
        return true;
    }
    
    int findRoot(int i, vector<int>& root) {
        if (root[i] != i) root[i] = findRoot(root[i], root);
        return root[i];
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> e = {{0,1}, {1,2}, {3,4}};
    cout << s.validTree(5, e) << endl;
    return 0;
}
