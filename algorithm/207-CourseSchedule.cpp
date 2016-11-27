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
class Solution_2 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.empty()) return true;

        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) graph[p.first].push_back(p.second);

        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && hasCycle(graph, i, visited, onpath)) return false;
        }
        return true;
    }

    bool hasCycle(vector<vector<int>>& graph, int cur, vector<bool>& visited, vector<bool>& onpath) {
        if (visited[cur]) return false;
        visited[cur] = true;
        onpath[cur] = true; // mark the node in current visiting path
        for (int nbr : graph[cur])
            if (onpath[nbr] || hasCycle(graph, nbr, visited, onpath)) return true;
        onpath[cur] = false;
        return false;
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> p = {{1,0}};
    cout << s.canFinish(2, p) << endl;
    return 0;
}

