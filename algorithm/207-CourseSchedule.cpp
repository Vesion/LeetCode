#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// A very good problem to practise BFS/DFS/topologocal sort


// Naturally, this problem is equivalent to detecting a cycle in a DAG.


// an auxiliary function to make a DAG
vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses);
    for (auto & p : prerequisites) graph[p.second].insert(p.first);
    return graph;
}

// Solution 1 : BFS
// BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we have found one. 
// We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. This process will be repeated for n (number of nodes) times. If we have not returned false, we will return true.

void getIndegree(vector<int>& indgree, vector<unordered_set<int>>& graph) {
    for (auto & p : graph)
        for (auto & nbr : p) indgree[nbr]++;
}

bool canFinish_BFS(int numCourses, vector<pair<int, int>>& prerequisites) {
    auto graph = makeGraph(numCourses, prerequisites);   
    vector<int> indgree(numCourses, 0); getIndegree(indgree, graph);
    for (int i = 0; i < numCourses; ++i) {
        int start = 0;
        while (start < numCourses) { if (!indgree[start]) break; ++start; } // try to find a node whose indgrees in 0
        if (start == numCourses) return false; // if cannot find one, there must be a cycle
        indgree[start] = -1; // prevent from visiting it again
        for (auto & nbr : graph[start]) --indgree[nbr];
    }
    return true;
}


// Solution 2 : DFS
// For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor... and so on. If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false. Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited. Note that you should make two records: one is to record all the visited nodes and the other is to record the visited nodes in the current DFS visit.
// The code is as follows. We use a vector<bool> visited to record all the visited nodes and another vector<bool> onpath to record the visited nodes of the current DFS visit. Once the current visit is finished, we reset the onpath value of the starting node to false.

bool hasCycle(vector<unordered_set<int>>& graph, int node, vector<bool>& visited, vector<bool>& onpath) {
    if (visited[node]) return false; // meet a visited node, return
    onpath[node] = visited[node] = true;
    for (auto & nbr : graph[node])
        if (onpath[nbr] || hasCycle(graph, nbr, visited, onpath))
            return true;
    onpath[node] = false; // backtracking recover
    return false;
}

bool canFinish_DFS(int numCourses, vector<pair<int, int>>& prerequisites) {
    auto graph = makeGraph(numCourses, prerequisites);
    vector<bool> visited(numCourses, false); // record nodes have been visited(completed)
    vector<bool> onpath(numCourses, false); // record nodes in visiting in a turn
    for (int i = 0; i < numCourses; ++i)
        if (!visited[i] && hasCycle(graph, i, visited, onpath)) // find a cycle
            return false;
    return true;
}


int main() {
    int numCourses = 2;
    vector<pair<int, int>> prerequisites = {{0, 1}};
    cout << canFinish_BFS(numCourses, prerequisites) << endl;
    cout << canFinish_DFS(numCourses, prerequisites) << endl;
    return 0;
}
