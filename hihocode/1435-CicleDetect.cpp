#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
#include <queue> 
using namespace std;


const int MAX = 100005;
bool visited[MAX], onpath[MAX];
unordered_map<int, unordered_set<int>> graph;

bool cycle(int cur) {
    if (visited[cur]) return false;
    visited[cur] = onpath[cur] = true;
    for (int nbr : graph[cur]) if (onpath[nbr] || cycle(nbr)) return true;
    onpath[cur] = false;
    return false;
}

string solve() {
    fill_n(visited, MAX, false);
    fill_n(onpath, MAX, false);
    graph.clear();
    int N, M;
    cin >> N >> M;
    while (M--) {
        int from, to;
        cin >> from >> to;
        graph[from].insert(to);
    }
    for (int i = 1; i <= N; ++i) {
        if (graph.count(i) && cycle(i)) return "YES";
    }
    return "NO";
}

int main() {
    int cases; cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}
