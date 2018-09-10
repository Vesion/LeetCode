#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Problem:
//      Given a graph G=(V,E), the Minimum Vertex Cover set is a vertex set S with minimum size, such that for every edge (u, v) in E, either u or v is in S.
//      It is a NP-Complete problem for any graph, but for a tree, we have two linear solutions, greedy and dp.
//
// Greedy solution:
//      Traverse the tree with postorder, for each node,
//      if one of it's children hasn't been put into S, we put this node into S (res++).
//
// e.g.
// http://poj.org/problem?id=1463

const int MAXN = 1505;
vector<int> tree[MAXN];
int N;
bool inset[MAXN];
int res;

void dfs(int cur, int par) {
    bool flag = false;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if (child == par) continue;
        dfs(child, cur);
        if (!inset[child]) flag = true;
    }
    if (flag) {
        inset[cur] = true;
        ++res; // put cur into S
    }
}

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; ++i) tree[i].clear();
        memset(inset, 0, sizeof inset);
        for (int i = 0; i < N; ++i) {
            int a, m; scanf("%d:(%d)", &a, &m);
            while (m--) { 
                int b; scanf("%d", &b); 
                tree[a].push_back(b);
                tree[b].push_back(a);
            }
        }
        res = 0;
        dfs(0, 0);
        printf("%d\n", res);
    }
    return 0;
}
