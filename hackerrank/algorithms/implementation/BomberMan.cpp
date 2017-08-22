#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 205;
char g[MAXN][MAXN];
int b[MAXN][MAXN];
int R, C;
long long N;

void fillB(int t) {
    for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) if (g[i][j] == '.') { g[i][j] = 'O'; b[i][j] = t; }
}

void clearB(int t) {
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            if (b[i][j] == t) g[i][j] = g[i-1][j] = g[i+1][j] = g[i][j-1] = g[i][j+1] = '.';
}

void print() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) putchar(g[i][j]);
        putchar('\n');
    }
}

int main() {
    scanf("%d %d %lld", &R, &C, &N); 
    for (int i = 1; i <= R; ++i) scanf("%s", g[i]+1);
    memset(b, -1, sizeof b);
    for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) if (g[i][j] == 'O') b[i][j] = 0;
    N = (N < 4 ? N : (4+N%4)); // think about it
    for (int i = 1; i <= N; ++i) {
        if (i&1) clearB(i-3);
        else fillB(i);
    }
    print();
    return 0;
}
