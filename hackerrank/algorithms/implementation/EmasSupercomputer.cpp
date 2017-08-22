#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 20;
char grid[MAXN][MAXN];
int N, M;

bool valid(int p, int q, int d) {
    if (grid[p][q] == 'B' || p-d < 0 || p+d >= N || q-d < 0 || q+d >= M) return false;
    for (int i = p-d; i <= p+d; ++i) if (grid[i][q] == 'B') return false;
    for (int j = q-d; j <= q+d; ++j) if (grid[p][j] == 'B') return false;
    return true;
}

void paint(int p, int q, int d, char c) {
    for (int i = p-d; i <= p+d; ++i) grid[i][q] = c;
    for (int j = q-d; j <= q+d; ++j) grid[p][j] = c;
}

int solve() {
    int L = (min(N,M)-1)/2;
    int res = 0;
    for (int d1 = L; d1 >= 0; --d1) {
        int s1 = 4*d1+1;
        if (s1*s1 <= res) break;
        for (int i1 = 0; i1 < N; ++i1) for (int j1 = 0; j1 < M; ++j1) if (valid(i1, j1, d1)) {
            paint(i1, j1, d1, 'B');
            for (int d2 = d1; d2 >= 0; --d2) {
                int s2 = 4*d2+1;
                for (int i2 = 0; i2 < N; ++i2) for (int j2 = 0; j2 < M; ++j2) if (valid(i2, j2, d2)) {
                    if (s1*s2 > res) {
                        res = s1*s2;
                    }
                }
            }
            paint(i1, j1, d1, 'G');
        }
    }
    return res;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> grid[i][j];
    cout << solve() << endl;
    return 0;
}
