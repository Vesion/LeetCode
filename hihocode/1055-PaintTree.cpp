#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 105;
int N, M;
int v[MAX];
vector<int> tree[MAX];
int dp[MAX][MAX];

void dfs(int cur, int parent, int m) {
    if (m == 0) return;
    dp[cur][1] = v[cur];
    for (int& child : tree[cur]) {
        if (child == parent) continue;
        dfs(child, cur, m-1);
        for (int i = m; i > 1; --i) {
            for (int j = 0; j < i; ++j) {
                dp[cur][i] = max(dp[cur][i], dp[cur][i-j] + dp[child][j]);
            }
        }
    }
}

int main() {
    cin >> N >> M; 
    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0, M);
    cout << dp[1][M] << endl;
    return 0;
}
