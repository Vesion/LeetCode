#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Prim Algorithm
// Straight-forward, O(V^2)

const int MAXN = 1005;
int g[MAXN][MAXN];
int dist[MAXN], has[MAXN];
int N;

int prim() {
    for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;
    dist[1] = 0;

    int res = 0;
    for (int i = 1; i <= N; ++i) {
        int d = INT_MAX, k;
        for (int j = 1; j <= N; ++j) {
            if (!has[j] && dist[j] < d) {
                k = j;
                d = dist[j];
            }
        }
        has[k] = true;
        res += dist[k];
        for (int j = 1; j <= N; ++j) {
            if (!has[j] && dist[j] > g[k][j])
                dist[j] = g[k][j];
        }
    }
    return res;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> g[i][j];
    cout << prim() << endl;
    return 0;
}
