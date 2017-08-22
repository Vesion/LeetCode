#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool f[10][10];
bool g[10][10];

int dfs(int n, int start, int given, int visited) {
    if (n == 1) return given == 0 ? 1 : 0;
    int res = 0;
    for (int i = 1; i <= 9; ++i) {
        if (!(visited&(1<<i))) {
            if (f[start][i] && !(visited&(1<<((i+start)/2)))) continue;
            if (g[start][i])
                res += dfs(n-1, i, given-1, visited|(1<<i)); 
            else 
                res += dfs(n-1, i, given, visited|(1<<i));
        }
    }
    return res;
}

int main() {
    memset(f, 0, sizeof f);
    f[1][3] = f[1][7] = f[1][9] = 
    f[3][1] = f[3][7] = f[3][9] = 
    f[7][1] = f[7][3] = f[7][9] = 
    f[9][1] = f[9][3] = f[9][7] = 
    f[2][8] = f[8][2] = f[4][6] = f[6][4] = true;
    int T; cin >> T; 
    while (T--) {
        memset(g, 0, sizeof g);
        int N; cin >> N;
        for (int i = 0; i < N; ++i) {
            int x, y; cin >> x >> y;
            g[y][x] = g[x][y] = true;
        }
        int res = 0;
        for (int c = 4; c <= 9; ++c) {
            for (int i = 1; i <= 9; ++i) res += dfs(c, i, N, 1<<i);
        }
        cout << res << endl;
    }
    return 0;
}
