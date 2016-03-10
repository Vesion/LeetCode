#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// based on 207-CourseSchedule, this problem require print topological sort


// an auxiliary function to make a DAG
vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses);
    for (auto & p : prerequisites) graph[p.second].insert(p.first);
    return graph;
}


// Solution 1 : BFS
void getIndegree(vector<int>& indgree, vector<unordered_set<int>>& graph) {
    for (auto & p : graph)
        for (auto & nbr : p) indgree[nbr]++;
}

vector<int> findOrder_BFS(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
    auto graph = makeGraph(numCourses, prerequisites);   
    vector<int> indgree(numCourses, 0); getIndegree(indgree, graph);
    for (int i = 0; i < numCourses; ++i) {
        int start = 0;
        while (start < numCourses) { if (!indgree[start]) break; ++start; }
        if (start == numCourses) return {};
        indgree[start] = -1;
        result.push_back(start); // 'start' node has been visited, push it to result
        for (auto & nbr : graph[start]) --indgree[nbr];
    }
    return result;
}


// Solution 2 : DFS
bool hasCycle(vector<unordered_set<int>>& graph, int node, vector<bool>& visited, vector<bool>& onpath, vector<int>& result) {
    if (visited[node]) return false;
    onpath[node] = visited[node] = true;
    for (auto & nbr : graph[node])
        if (onpath[nbr] || hasCycle(graph, nbr, visited, onpath, result))
            return true;
    onpath[node] = false;
    result.push_back(node); // here we push nodes which are latter been visited into front of those are firstly been visited, so a final reversal is required
    return false;
}

vector<int> findOrder_DFS(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
    auto graph = makeGraph(numCourses, prerequisites);
    vector<bool> visited(numCourses, false);
    vector<bool> onpath(numCourses, false);
    for (int i = 0; i < numCourses; ++i)
        if (!visited[i] && hasCycle(graph, i, visited, onpath, result))
            return {};
    reverse(result.begin(), result.end()); // reverse to generate topological sequence
    return result;
}


int main() {
    vector<pair<int, int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    //vector<pair<int, int>> prerequisites = {{0,1},{3,1},{1,3},{3,2}};
    //auto result = findOrder_BFS(4, prerequisites);
    auto result = findOrder_DFS(4, prerequisites);
    for (auto i:result) cout << i << " "; cout << endl;
    return 0;
}
