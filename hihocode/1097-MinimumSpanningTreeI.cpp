#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 1005;
int g[MAXN][MAXN];
int dist[MAXN], has[MAXN];
int N;
int res;

void prim() {
    for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;
    dist[1] = 0;

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
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> g[i][j];
    res = 0;
    prim();
    cout << res << endl;
    return 0;
}
