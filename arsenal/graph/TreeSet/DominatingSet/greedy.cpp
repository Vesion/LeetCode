#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Problem:
//      Given a graph G=(V,E), the Minimum Dominating Set is a vertex set S with minimum size, for any v in V but not in S, has an edge connecting u in S.
//      It is a NP-Complete problem for any graph, but for a tree, we have two linear solutions, greedy and dp.
//
// Greedy solution:
//      Traverse the tree with postorder, for each node, 
//      if it and it's parent haven't been put into S, and none of its children have been put into S, we put it's parent into S (res++).
//
// e.g.
// http://poj.org/problem?id=3659

const int MAXN = 1e5+5;
vector<int> tree[MAXN];
int N;
bool inset[MAXN];
int res = 0;

void dfs(int cur, int par) {
    bool flag = false;
    for (int& child : tree[cur]) {
        if (child == par) continue;
        dfs(child, cur);
        flag |= inset[child];
    }
    if (!inset[par] && !inset[cur] && !flag) {
        inset[par] = true;
        ++res; // put parent into S
    }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 1);
    return 0;
}
