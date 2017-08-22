#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 210;

char m[MAX][MAX];
char h[3][3];
int N, M;

bool same(int x, int y) {
    bool r0 = true, r90 = true, r180 = true, r270 = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (r0 && m[x+i][y+j] != h[i][j]) r0 = false;
            if (r90 && m[x+2-j][y+i] != h[i][j]) r90 = false;
            if (r180 && m[x+2-i][y+2-j] != h[i][j]) r180 = false;
            if (r270 && m[x+j][y+2-i] != h[i][j]) r270 = false;

        }
    }
    return r0 || r90 || r180 || r270;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M; 
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> m[i][j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> h[i][j];

    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < M-1; ++j) {
            if (m[i][j] == h[1][1] && same(i-1, j-1))
                cout << i+1 << " " << j+1 << endl;
        }
    }

    return 0;
}
