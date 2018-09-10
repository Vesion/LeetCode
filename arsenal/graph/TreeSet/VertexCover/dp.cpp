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
// DP solution:
//      dp[i][0] means the minimum S for subtree with root i, when we don't put i into S
//      dp[i][1] means the minimum S for subtree with root i, when we put i into S
//      so,
//      dp[i][0] = sum{ dp[j][1] }, j is child of i
//      dp[i][1] = 1 + sum{ min(dp[j][0], dp[j][1]) }, j is child of i
//
// e.g.
// http://poj.org/problem?id=1463

const int MAXN = 1505;
vector<int> tree[MAXN];
int N;
int dp[MAXN][2];

void dfs(int cur, int par) {
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if (child == par) continue;
        dfs(child, cur);
        dp[cur][0] += dp[child][1];
        dp[cur][1] += min(dp[child][0], dp[child][1]);
    }
}


int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; ++i) tree[i].clear();
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < N; ++i) {
            int a, m; scanf("%d:(%d)", &a, &m);
            while (m--) { 
                int b; scanf("%d", &b); 
                tree[a].push_back(b);
                tree[b].push_back(a);
            }
        }
        dfs(0, 0);
        printf("%d\n", min(dp[0][0], dp[0][1]));
    }
    return 0;
}
