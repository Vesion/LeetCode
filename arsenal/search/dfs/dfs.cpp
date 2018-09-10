#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set> 
#include <string>
using namespace std;

void dfs(vector<unordered_set<int>> &graph, int cur, vector<bool> &visited) {
    if (visited[cur]) return;
    visited[cur] = true;

    // previsit cur
    
    for (int x : graph[cur])
        dfs(graph, x, visited);

    // postvisit cur
}

int main() {
    vector<unordered_set<int>> g(5);
    g[0].insert(1);
    g[0].insert(2);
    g[1].insert(3);
    g[2].insert(4);
    
    vector<bool> v(5, false);
    
    dfs(g, 0, v);
    return 0;
}
