#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 
#include <climits> 
#include <queue> 
using namespace std;

// Dijkstra, straight forward, O(V^2) time

const int MAX = 1e3+5;
int g[MAX][MAX];
bool has[MAX];
int dist[MAX];
int N, M, S, T;

void init() {
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) g[i][j] = INT_MAX;
    for (int i = 1; i <= N; ++i) g[i][i] = 0;
}

void dijkstra(int s) {
    for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;
    dist[s] = 0;

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
    init();
    while (M--) {
        int a, b, l; cin >> a >> b >> l;
        g[a][b] = g[b][a] = min(g[a][b], l);
    }
    dijkstra(S);
    cout << dist[T] << endl;
    return 0;
}
