#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set> 
#include <queue> 
#include <string>
using namespace std;

void bfs(vector<unordered_set<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);

    queue<pair<int, int>> q;
    q.push({start, 0});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        if (visited[p.first]) continue;
        visited[p.first] = true;

        // visite p
        //cout << p.first << " : " << p.second << endl;
        
        for (int x : graph[p.first]) q.push({x, p.second+1});
    }
}

int main() {
    vector<unordered_set<int>> g(5);
    g[0].insert(1);
    g[0].insert(2);
    g[1].insert(3);
    g[2].insert(4);

    bfs(g, 0);
    return 0;
}
