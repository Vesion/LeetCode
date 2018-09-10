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
// DP solution:
//      dp[i][0] means the minimum S for subtree with root i, when we put i into S
//      dp[i][1] means the minimum S for subtree with root i, when we don't put i into S, i is covered by it's children
//      dp[i][2] means the minimum S for subtree with root i, when we don't put i into S, i is covered by it's parent
//      so,
//      dp[i][0] = 1 + sum{ min(dp[j][0], dp[j][1], dp[j][2]) }, j is child of i
//      dp[i][1] = sum{ min(dp[j][0], dp[j][1] }, j is child of i
//          but, if it happens to we all take dp[j][1], i.e. none of i's children is put into S to cover i, we have to put at least one child into S
//          so we need to record whether we take a dp[j][0] or not, if not, we take the minimum dp[j][0]
//      dp[i][2] = sum{ min(dp[j][0], dp[j][1] }, j is child of i
//
// e.g.
// http://poj.org/problem?id=3659

const int MAXN = 1e4+5;
vector<int> tree[MAXN];
int dp[MAXN][3];
int N;

void dfs(int cur, int par) {
    dp[cur][0] = 1;
    dp[cur][1] = dp[cur][2] = 0;
    int mind = INT_MAX, c = 0;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if (child == par) continue;
        dfs(child, cur);
        dp[cur][0] += min(dp[child][0], min(dp[child][1], dp[child][2]));
        dp[cur][2] += min(dp[child][0], dp[child][1]);
        if (dp[child][0] <= dp[child][1]) {
            ++c;
            dp[cur][1] += dp[child][0];
        } else {
            dp[cur][1] += dp[child][1];
            mind = min(mind, dp[child][0]-dp[child][1]);
        }
    }
    if (c == 0) dp[cur][1] += mind;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 1);
    cout << min(dp[1][0], dp[1][1]) << endl;;
    return 0;
}
