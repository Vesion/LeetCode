#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 12;
int a[MAXN][MAXN];
int b[MAXN][MAXN], m[MAXN][MAXN], c;
int N, M;

int go[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool valid() {
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (a[i][j] == -1) continue;
        int x = 0;
        for (int d = 0; d < 8; ++d) {
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && m[ni][nj] == 1) ++x;
        }
        if (x != a[i][j]) {
            return false;
        }
    }
    return true;
}

void dfs(int id) {
    if (id == N*M) {
        if (valid()) {
            ++c;
            for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (m[i][j] == 1) b[i][j]++;
            for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (m[i][j] == -1) b[i][j]--;
        }
        return;
    }
    int i = id/M, j = id%M;
    if (a[i][j] == -1) {
        m[i][j] = 1;
        dfs(id+1);
        m[i][j] = -1;
        dfs(id+1);
    } else dfs(id+1);
}

int main() {
    int T; cin >> T; while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> a[i][j];
        memset(b, 0, sizeof b);
        memset(m, 0, sizeof m);
        c = 0;
        dfs(0);
        int r0 = 0, r1 = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
            if (b[i][j] == c) ++r1;
            if (b[i][j] == -c) ++r0;
        }
        cout << r1 << " " << r0 << endl;
    }
    return 0;
}
