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
// DP solution:
//      dp[i][0] means the largest S for subtree with root i, when we don't put i into S
//      dp[i][1] means the largest S for subtree with root i, when we put i into S
//      so,
//      dp[i][0] = sum{ max(dp[j][0], dp[j][1] }, j is child of i
//      dp[i][1] = sum{ dp[j][0] }, j is child of i
//
// e.g.
// http://poj.org/problem?id=3342

const int MAXN = 1e4+5;
vector<int> tree[MAXN];
int dp[MAXN][2];
int N;

void dfs(int cur) {
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        dfs(child);
        dp[cur][0] += max(dp[child][0], dp[child][1]);
        dp[cur][1] += dp[child][0];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}

