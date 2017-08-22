#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int CMAX = 120;
const int SMAX = 1020;

int K;
char c[CMAX][CMAX];
char s[SMAX][SMAX];

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};
vector<vector<Point>> m;

int main() {
    ios::sync_with_stdio(false);
    cin >> K;
    while (K--) {
        int H, W;
        int si = -1, sj = -1;
        vector<Point> ps;
        cin >> H >> W;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> c[i][j];
                if (c[i][j] == '#') {
                    if (si == -1) {
                        si = i, sj = j;
                        ps.push_back({i, j});
                    } else ps.push_back({i-si, j-sj});
                }

            }
        }
        m.push_back(ps);
    }

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> s[i][j];

    for (auto& ps : m) {
        if (ps.empty()) {
            cout << "No" << endl;
            continue;
        }
        bool f = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (s[i][j] == '#') {
                    bool found = true;
                    for (int k = 1; k < (int)ps.size(); ++k) {
                        int ci = ps[k].x+i, cj = ps[k].y+j;
                        if (ci < 0 || ci >= N || cj < 0 || cj >= M || s[ci][cj] == '.') {
                            found = false;
                            break;
                        }
                    }
                    f |= found;
                }
            }
        }
        if (f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
