#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 110;
const int inf = -2147483647;
const int ext = 20000;

int N, K, M;
int v[MAX]; // values
int dp[MAX][MAX]; // the max values of starting from root i, visiting j children nodes
vector<int> e[MAX];

// 从左往右遍历子树，每新遍历完一颗子树，就有可能对这颗树的结果产生影响，就要重新更新结果
void dfs(int root, int parent) {
    dp[root][1] = v[root];
    for (int i = 0; i < (int)e[root].size(); ++i) {
        if (e[root][i] == parent) continue;
        dfs(e[root][i], root); // 遍历子树
        // 因为有了一个新的子树加入，所以要考虑新子树对结果的影响
        for (int x = M; x >= 1; --x) {
            for (int y = 0; y <= M-x; ++y) {
                dp[root][x+y] = max(dp[root][x+y], dp[root][x] + dp[e[root][i]][y]);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K >> M;
    for (int i = 1; i <= N; ++i) 
        cin >> v[i];
    int t;
    for (int i = 1; i <= K; ++i) {
        cin >> t;
        v[t] += ext;
    }
    int a, b;
    for (int i = 1; i < N; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    if (K > M) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) dp[i][j] = inf;
    dfs(1, 0);
    cout << dp[1][M] % ext << endl;
    return 0;
}
