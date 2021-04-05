#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : BFS, 42ms
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            ++res;
            q.push(i);
            while (!q.empty()) {
                int t = q.front(); q.pop();
                visited[t] = true;
                for (int nbr : graph[t]) {
                    if (!visited[nbr]) q.push(nbr);
                }
            }
        }
        return res;
    }
};


// Solution 2 : DFS, 26 ms
class Solution_2 {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            ++res;
            dfs(graph, i, visited);
        }
        return res;
    }

    void dfs(vector<vector<int>>& graph, int cur, vector<bool>& visited) {
        visited[cur] = true;
        for (int nbr : graph[cur]) {
            if (!visited[nbr]) dfs(graph, nbr, visited);
        }
    }
};


// Solution 3 : Union Find, 13ms
class Solution_3 {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);
        for (auto& e : edges) {
            int r1 = findRoot(e[0], root);
            int r2 = findRoot(e[1], root);
            if (r1 != r2) root[r1] = r2;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) if (root[i] == i) ++res;
        return res;
    }

    int findRoot(int i, vector<int>& root) {
        if (i != root[i]) root[i] = findRoot(root[i], root);
        return root[i];
    }
};


int main() {
    return 0;
}
