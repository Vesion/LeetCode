#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 
#include <cstdlib> 
using namespace std;

// This problem has a trap:
//      when output, we only print '1' visited in this turn!

const int MAX = 550;
int N, M;
char W[MAX][MAX];
int f[MAX][MAX];
int go[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int l1, r1, l2, r2;

void solve(int i, int j) {
    f[i][j] = 1;
    l1 = min(l1, i), r1 = min(r1, j), l2 = max(l2, i), r2 = max(r2, j);
    for (int k = 0; k < 4; ++k) {
        int ni = i+go[k][0], nj = j+go[k][1];
        if (W[ni][nj] == '1' && !f[ni][nj]) solve(ni, nj);
    }
}


int main() {
    cin >> N >> M; 
    memset(W, 0, sizeof W);
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) cin >> W[i][j];

    for (int j = 1; j <= M; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (W[i][j] == '1' && !f[i][j]) {
                l1 = N+1, r1 = M+1, l2 = 0, r2 = 0;
                solve(i, j);
                cout << l2-l1+1 << " " << r2-r1+1 << endl;
                for (int p = l1; p <= l2; ++p) {
                    for (int q = r1; q <= r2; ++q) {
                        if (f[p][q] == 1) {
                            cout << '1';
                            ++f[p][q]; // increase its turn
                        }
                        else cout << '0';
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
