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
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
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
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        vector<bool> visited(n, false);
        queue<int> q;
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
    int countComponents(int n, vector<pair<int, int>>& edges) {
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        count = n;

        for (auto& e : edges) unionSet(e.first, e.second);
        return count;
    }

    vector<int> root;
    int count;

    void unionSet(int i, int j) {
        int ri = findRoot(i), rj = findRoot(j);
        if (ri != rj) {
            root[ri] = rj;
            --count;
        }
    }

    int findRoot(int i) {
        if (root[i] == i) return i;
        root[i] = findRoot(root[i]);
        return root[i];
    }
};



int main() {
    Solution s;
    vector<pair<int,int>> e = {{0,1}, {1,2}, {3,4}};
    cout << s.countComponents(5, e) << endl;
    return 0;
}
