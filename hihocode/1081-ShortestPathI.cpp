#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 1005;
int g[MAXN][MAXN];
int dist[MAXN];
bool has[MAXN];
int N, M, S, T;

void dijkstra(int s) {
    for (int i = 1; i <= N; ++i) dist[i] = g[s][i];
    dist[s] = 0; has[s] = true;

    for (int i = 1; i <= N; ++i) {
        int d = INT_MAX, k;
        for (int j = 1; j <= N; ++j) {
            if (!has[j] && dist[j] < d) {
                d = dist[j];
                k = j;
            }
        }
        has[k] = true;
        for (int j = 1; j <= N; ++j) {
            if (!has[j] && g[k][j] != INT_MAX)
                dist[j] = min(dist[j], dist[k]+g[k][j]);
        }
    }
}

int main() {
    cin >> N >> M >> S >> T; 
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) g[i][j] = INT_MAX;
    for (int i = 1; i <= N; ++i) g[i][i] = 0;
    while (M--) {
        int a, b, l; cin >> a >> b >> l;
        g[a][b] = g[b][a] = min(g[a][b], l);
    }
    dijkstra(S);
    cout << dist[T] << endl;
    return 0;
}
