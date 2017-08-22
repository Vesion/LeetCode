#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

const int MAX = 110;
const int INF = 0x0fffffff;

struct Point {
    int i, j;
    Point(int x, int y) : i(x), j(y) {}
};

int N, M;
char g[MAX][MAX];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int si, sj;
vector<pair<Point, int>> r;

void bfs() {
    queue<pair<Point, int>> q;
    q.push({{si, sj}, 0});
    g[si][sj] = 'P';
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int ci = p.first.i, cj = p.first.j;

        if (g[ci][cj] == 'S') {
            r.push_back({{ci, cj}, p.second});
            continue;
        }

        for (int d = 0; d < 4; ++d) {
            int ni = ci + go[d][0];
            int nj = cj + go[d][1];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && g[ni][nj] != '#' && g[ni][nj] != 'P') {
                if (g[ni][nj] == '.') g[ni][nj] = 'P';
                q.push({{ni, nj}, p.second+1});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'H') {
                si = i, sj = j;
            }
        }
    }

    bfs();
    int n = r.size();
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ix = r[i].first.i; int iy = r[i].first.j;
            int jx = r[j].first.i; int jy = r[j].first.j;
            if (i != j && abs(ix-jx)+abs(iy-jy) == 1)
                ans = min(ans, r[i].second + r[j].second);
        }
    }
    if (ans == INF) cout << "Hi and Ho will not have lunch." << endl;
    else cout << ans << endl;

    return 0;
}
