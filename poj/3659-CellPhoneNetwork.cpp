#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e4+5;
vector<int> tree[MAXN];
int dp[MAXN][3];
int N;

void dfs(int cur, int par) {
    dp[cur][0] = 1;
    dp[cur][1] = dp[cur][2] = 0;
    bool flag = false;
    int mind = INT_MAX;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if (child == par) continue;
        dfs(child, cur);
        dp[cur][0] += min(dp[child][0], min(dp[child][1], dp[child][2]));
        dp[cur][2] += min(dp[child][0], dp[child][1]);
        if (dp[child][0] <= dp[child][1]) {
            flag = true;
            dp[cur][1] += dp[child][0];
        } else {
            dp[cur][1] += dp[child][1];
            mind = min(mind, dp[child][0]-dp[child][1]);
        }
    }
    if (!flag) dp[cur][1] += mind;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 1);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}
