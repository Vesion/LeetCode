#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Minimum Dominating Set

const int MAXN = 1e5+5;
vector<int> tree[MAXN];
int burnout[MAXN];
int dp[MAXN][3];
int N;

void dfs(int cur) {
    dp[cur][0] = 1;
    dp[cur][1] = dp[cur][2] = 0;
    int mind = INT_MAX, c = 0;
    for (int& child : tree[cur]) {
        dfs(child);
        dp[cur][0] += min(dp[child][0], min(dp[child][1], dp[child][2]));
        dp[cur][2] += min(dp[child][0], dp[child][1]);
        if (dp[child][0] <= dp[child][1]) {
            dp[cur][1] += dp[child][0];
            ++c;
        } else {
            dp[cur][1] += dp[child][1];
            mind = min(mind, dp[child][0]-dp[child][1]);
        }
    }
    if (c == 0 && burnout[cur]) dp[cur][1] += mind;
}

int main() {
    scanf("%d", &N);    
    for (int i = 1; i < N; ++i) {
        int x, b; scanf("%d %d", &x, &b);
        tree[x].push_back(i);
        burnout[i] = 1-b;
    }
    dfs(0);
    printf("%d\n", min(dp[0][0], dp[0][1]));
    return 0;
}
