#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Problem:
//      Given a graph G=(V,E), the Largest Independent Set is a vertex set S with maximum size, such that for every edge (u, v) in E, at most one vertex is in S.
//      It is a NP-Complete problem for any graph, but for a tree, we have two linear solutions, greedy and dp.
//
// Greedy solution:
//      Traverse the tree with post order, for each node:
//      if it hasn't been put into S, we put it int S (res++), and mark it and it's parent as covered.
//
// e.g.
// http://poj.org/problem?id=3342

const int MAXN = 1e4+5;
vector<int> tree[MAXN];
bool cover[MAXN];
int N;
int res;

void dfs(int cur, int par) {
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if (child == par) continue;
        dfs(child, cur);
    }
    if (!cover[cur]) {
        ++res; // put cur into S
        cover[cur] = cover[par] = true;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    res = 0;
    dfs(1, 1);
    cout << res << endl;
    return 0;
}
