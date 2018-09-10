#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://agc013.contest.atcoder.jp/tasks/agc013_b
//
// Problem:
//      Given a connected undirected simple graph, find a Hamiltonian Path (any one is OK)
//
// Solution:
//      DFS from any vertex i, to any vertex which cannot go forward here, we get path 1;
//      Then DFS from i again, get path 2;
//      reverse path 1, then append path 2

const int MAX = 1e5+5;
vector<int> graph[MAX];
int visited[MAX];
vector<int> res;
int N, M;

void dfs(int cur) {
    res.push_back(cur);
    visited[cur] = true;
    for (int& child : graph[cur]) {
        if (!visited[child]) {
            dfs(child);
            return;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    reverse(res.begin(), res.end());
    res.pop_back();
    dfs(1);
    cout << res.size() << endl;
    for (int& i : res) cout << i << " ";
    return 0;
}
