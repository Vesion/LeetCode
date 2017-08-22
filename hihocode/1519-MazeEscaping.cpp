#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <queue> 
using namespace std;

const int MAXN = 505;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int si, sj;

int go[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int solve() {
    queue<pair<int,int>> q;
    visited[si][sj] = true;
    q.push({si, sj});
    int s = 0;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            int i = q.front().first, j = q.front().second; q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i, nj = j;
                while (ni >= 0 && ni < N && nj >= 0 && nj < M && maze[ni][nj] != '#') {
                    if (maze[ni][nj] == 'T') return s;
                    ni += go[d][0], nj += go[d][1];
                }
                ni -= go[d][0], nj -= go[d][1];
                if (!visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        ++s;
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M); 
    for (int i = 0; i < N; ++i) scanf("%s", maze[i]);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (maze[i][j] == 'S') si = i, sj = j;
    cout << solve() << endl;
    return 0;
}
