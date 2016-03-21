#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// The famous MHTs problem.

// Solution 1 : Similar to 207-CourseSchedule, use bfs to delete leaves layer-by-layer, until reach the root
void makeDAG(vector<pair<int, int>>& edges, vector<unordered_set<int>>& dag) {
    for (auto & p : edges) {
        dag[p.first].insert(p.second);
        dag[p.second].insert(p.first);
    }
}

void calIndegrees(vector<unordered_set<int>>& dag, vector<int>& indegrees) {
    for (int i = 0; i < dag.size(); ++i)
        indegrees[i] += dag[i].size();
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return {0};
    if (n == 2) return {0, 1};
    vector<unordered_set<int>> dag(n); makeDAG(edges, dag); // build DAG
    vector<int> indegrees(n, 0); calIndegrees(dag, indegrees); // calculate all nodes' indegrees, for a leaf, its indegree is 1

    vector<int> cur, next; // current layer leaves and next layer
    for (int i = 0; i < n; ++i) if (indegrees[i] == 1) cur.push_back(i); // find the outermost layer leaves
    while (true) { // remove leaves layer by layer
        for (auto &leaf : cur) {
            indegrees[leaf] = 0;
            for (auto &nbr : dag[leaf]) if (--indegrees[nbr] == 1) next.push_back(nbr);
        }
        if (next.empty()) return cur; // if no next layer leaves, current layer leaves are roots we want
        cur = next; next.clear();
    }
    return {}; // never
}

int main() {
    vector<pair<int, int>> edges = {
        {0, 3}, 
        {1, 3}, 
        {2, 3}, 
        {4, 3}, 
        {5, 4}
    };
    auto r = findMinHeightTrees(6, edges);
    for (auto i : r) cout << i << endl;
    return 0;
}
