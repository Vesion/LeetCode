#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// DP
//      dp[i][j][k] means the shortest path start from i to j, goes through nodes which are no greater than k
//
//      dp[i][j][k] = min(   dp[i][j][k-1]   ,   dp[i][k][k-1]+dp[k][j][k-1]   );
//                          not go through k        go through k


const int MAXN = 105;

int g[MAXN][MAXN];
int N, M;

void init() {
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) g[i][j] = INT_MAX; 
    for (int i = 1; i <= N; ++i) g[i][i] = 0;
}

void floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if(g[i][k] != INT_MAX && g[k][j] != INT_MAX) 
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}

int main() {
    cin >> N >> M; 
    init();
    while (M--) {
        int a, b, l; cin >> a >> b >> l;
        g[a][b] = g[b][a] = min(g[a][b], l); 
    }
    floyd();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
