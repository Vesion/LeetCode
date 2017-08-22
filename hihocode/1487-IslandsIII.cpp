#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000;
int m[MAX][MAX];
int N;
int go[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int c, a, p;
int root[MAX*MAX+10];

int findRoot(int i) {
    if (root[i] != i) root[i] = findRoot(root[i]);
    return root[i];
}

void unionSet(int x1, int y1, int x2, int y2) {
    int r1 = findRoot(x1*MAX+y1), r2 = findRoot(x2*MAX+y2);
    p -= 2;
    if (r1 == r2) return;
    root[r1] = r2;
    --c;
}

int main() {
    for (int i = 0; i < MAX*MAX+10; ++i) root[i] = i;
    scanf("%d", &N);
    while (N--) {
        int x, y; cin >> x >> y;
        if (x < 0 || x >= MAX || y < 0 || y >= MAX || m[x][y] == 1) continue;
        m[x][y] = 1;
        ++c; ++a; p += 4;
        for (int d = 0; d < 4; ++d) {
            int nx = x+go[d][0], ny = y+go[d][1];
            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || m[nx][ny] == 0) continue;
            unionSet(x, y, nx, ny);
        }
        printf("%d %d %d\n", c, a, p);
    }
    return 0;
}
