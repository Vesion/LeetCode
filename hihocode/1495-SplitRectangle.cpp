#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue> 
using namespace std;

const int MAX = 105;
int m[MAX][MAX];

struct half {
    int h[2];
};
half c[MAX][MAX];
int N, M;
int res = 1;
int go[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void paint(int i, int j, int d) {
    if (i < 0 || i >= N || j < 0 || j >= M) return;
    if (m[i][j] == 0) {
        if (c[i][j].h[0] != 0 || c[i][j].h[1] != 0) return;
        c[i][j].h[0] = c[i][j].h[1] = res;
        paint(i, j+1, 0);
        paint(i+1, j, 1);
        paint(i, j-1, 2);
        paint(i-1, j, 3);
    }
    else if (m[i][j] == 1) {
        if (d == 0 || d == 1) {
            if (c[i][j].h[0] != 0) return;
            c[i][j].h[0] = res;
            paint(i, j-1, 2);
            paint(i-1, j, 3);
        } else {
            if (c[i][j].h[1] != 0) return;
            c[i][j].h[1] = res;
            paint(i, j+1, 0);
            paint(i+1, j, 1);
        }
    } else {
        if (d == 0 || d == 3) {
            if (c[i][j].h[0] != 0) return;
            c[i][j].h[0] = res;
            paint(i+1, j, 1);
            paint(i, j-1, 2);
        } else {
            if (c[i][j].h[1] != 0) return;
            c[i][j].h[1] = res;
            paint(i, j+1, 0);
            paint(i-1, j, 3);
        }
    }
}

int main() {
    cin >> N >> M; 
    cin.get();
    for (int i = 0; i < N; ++i) {
        string s;
        getline(cin, s);
        for (int j = 0; j < M; ++j) {
            if (s[j] == '/') m[i][j] = 1;
            else if (s[j] == '\\') m[i][j] = 2;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (c[i][j].h[0] == 0) {
                //cout << i << " " << j << " " << res << endl;
                if (m[i][j] == 0) paint(i, j, 0);
                else if (m[i][j] == 1) paint(i, j, 0);
                else paint(i, j, 0);
                ++res;
            }
            if (c[i][j].h[1] == 0) {
                //cout << i << " " << j << " " << res << endl;
                if (m[i][j] == 0) paint(i, j, 0);
                else if (m[i][j] == 1) paint(i, j, 2);
                else paint(i, j, 2);
                ++res;
            }
        }
    }
    cout << res-1 << endl;
    return 0;
}
