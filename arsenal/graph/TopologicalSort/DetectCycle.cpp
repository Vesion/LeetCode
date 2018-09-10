#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <queue> 
using namespace std;

// Given a graph G, detect cycle in it.

// Directed graph

// Solution 1 : BFS, count indegrees, O(V+E)
class Solution_D1 {
public:
    bool hasCycle(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegrees(n, 0);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            indegrees[e.second]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (indegrees[i] == 0) q.push(i);

        int count = 0;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            ++count;
            for (int& nbr : graph[t]) if (--indegrees[nbr] == 0) q.push(nbr);
        }
        return count != n;
    }
};

// Solution 2 : DFS, keep track of vertices in recursion stack (on path), O(V+E)
class Solution_D2 {
public:
    bool hasCycle(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) graph[e.first].push_back(e.second);

        vector<bool> visited(n, false);
        vector<bool> onpath(n, false);
        for (int i = 0; i < n; ++i) 
            if (hasCycle(graph, i, visited, onpath)) return true;
        return false;
    }

    bool hasCycle(vector<vector<int>>& graph, int cur, vector<bool>& visited, vector<bool>& onpath) {
        if (visited[cur]) return false;
        visited[cur] = onpath[cur] = true;
        for (int& nbr : graph[cur]) {
            if (onpath[nbr] || hasCycle(graph, nbr, visited, onpath)) return true;
        }
        onpath[cur] = false;
        return false;
    }
};



// Undirected graph

// Solution 1 : DFS, O(V+E)
// similar to Solution_D2, but here we don't need an extra onpath table, we cau reuse the visited table as the recursion stack and a parent node to avoid go back
class Solution_U1 {
public:
    bool hasCycle(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) 
            if (!visited[i] && hasCycle(graph, i, -1, visited)) return true;
        return false;
    }

    bool hasCycle(vector<vector<int>>& graph, int cur, int parent, vector<bool>& visited) {
        if (visited[cur]) return true;
        visited[cur] = true;
        for (int& nbr : graph[cur]) {
            if (nbr != parent && hasCycle(graph, nbr, cur, visited)) return true;
        }
        return false;
    }
};


// Solution 2 : Union Find, O(E*(log*V))
class Solution_U2 {
public:
    bool hasCycle(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);
        for (auto& e : edges) {
            int ri = findRoot(root, e.first);
            int rj = findRoot(root, e.second);
            if (ri == rj) return true;
            root[ri] = rj;
        }        
        return false;
    }

    int findRoot(vector<int>& root, int i) {
        if (i != root[i]) root[i] = findRoot(root, root[i]);
        return root[i];
    }
};


int main() {
    vector<pair<int,int>> edges = {{0, 1}, {1, 2}};
    Solution_D1 sd1;
    Solution_D2 sd2;
    Solution_U1 su1;
    Solution_U2 su2;
    cout << sd1.hasCycle(3, edges) << endl;
    cout << sd2.hasCycle(3, edges) << endl;
    cout << su1.hasCycle(3, edges) << endl;
    cout << su2.hasCycle(3, edges) << endl;
    return 0;
}
