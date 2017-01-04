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
class Solution_2 {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) graph[p.second].push_back(p.first);

        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
            if (hasCycle(i, graph, visited, onpath, res)) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    } 

    bool hasCycle(int cur, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onpath, vector<int>& res) {
        if (visited[cur]) return false;
        visited[cur] = onpath[cur] = true;
        for (int nbr : graph[cur])
            if (onpath[nbr] 
            || hasCycle(nbr, graph, visited, onpath, res)) return true;
        onpath[cur] = false;
        res.push_back(cur);
        return false;
    }
};


int main() {
    Solution_2 s;
    vector<pair<int,int>> p = {{1,0}};
    s.findOrder(2, p);
    return 0;
}

