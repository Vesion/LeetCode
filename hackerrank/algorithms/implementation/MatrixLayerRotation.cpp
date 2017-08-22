#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 305;
int a[MAXN][MAXN], b[MAXN][MAXN];
int M, N, R;

pair<int,int> convert(int s, int i, int rowc, int colc, int tc) {
    if (i < colc) {
        return {s+i, s};
    } else if (i < colc+rowc-1) {
        return {s+colc-1, s+i-colc+1};
    } else if (i < 2*colc+rowc-2) {
        return {s+tc-i-rowc+1, s+rowc-1};
    } else {
        return {s, s+tc-i};
    }
}

int main() {
    cin >> M >> N >> R;
    for (int i = 0; i < M; ++i) for (int j = 0; j < N; ++j) cin >> a[i][j];
    for (int s = 0; s < min(M, N)/2; ++s) {
        int rowc = N-2*s, colc = M-2*s;
        int tc = 2*rowc + 2*colc - 4;
        for (int i = 0; i < tc; ++i) {
            int j = (i+R)%tc;
            auto p = convert(s, i, rowc, colc, tc);
            auto q = convert(s, j, rowc, colc, tc);
            b[q.first][q.second] = a[p.first][p.second];
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}
