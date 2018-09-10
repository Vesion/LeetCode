#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 
#include <queue> 
using namespace std;

// Problem:
//      Given a N*M matrix, '.' for empty, 'X' for player, '*' for sb, '#' for wall, '@' for destination
//      What is the minimum moves the player needs to push the box to destination.
// Solution:
//      BFS, but here we have to store not only player's position, but the sb's position

int N, M;
char matrix[10][10];
bool visited[10][10][10][10];
int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

struct Pos {
    int x, y;
    bool operator== (const Pos& p) const { return x == p.x && y == p.y; }
};
Pos sp, sb;

int bfs() {
    queue<pair<Pos,Pos>> q;
    q.push({sp, sb});
    visited[sp.x][sp.y][sb.x][sb.y] = true;;
    int res = 0;
    while (!q.empty()) {
        ++res;
        int len = q.size();
        while (len--) {
            Pos p = q.front().first, b = q.front().second; q.pop();
            for (int d = 0; d < 4; ++d) {
                Pos np = {p.x+go[d][0], p.y+go[d][1]};
                if (np.x < 0 || np.x >= N || np.y < 0 || np.y >= M || matrix[np.x][np.y] == '#') continue; // validate player
                Pos nb = b;
                if (np == b) nb = {b.x+go[d][0], b.y+go[d][1]};
                if (nb.x < 0 || nb.x >= N || nb.y < 0 || nb.y >= M || matrix[nb.x][nb.y] == '#') continue; // validate box
                if (visited[np.x][np.y][nb.x][nb.y]) continue;
                if (matrix[nb.x][nb.y] == '@') return res;
                q.push({np, nb});
                visited[np.x][np.y][nb.x][nb.y] = true;
            }
        }
    }
    return -1;
}

int main() {
    memset(matrix, 0, sizeof matrix); 
    memset(visited, 0, sizeof visited);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'X') sp = {i, j};
            else if (matrix[i][j] == '*') sb = {i, j};
        }
    }
    cout << bfs() << endl;
    return 0;
}

