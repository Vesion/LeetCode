#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e3+5;
char g[MAXN][MAXN];
char p[MAXN][MAXN];
int gr, gc, pr, pc;

bool equal(int r, int c) {
    for (int i = 0; i < pr; ++i) for (int j = 0; j < pc; ++j) if (g[r+i][c+j] != p[i][j]) return false;
    return true;
}

bool search() {
    for (int i = 0; i < gr; ++i) {
        for (int j = 0; j < gc; ++j) {
            if (equal(i, j)) return true;
        }
    }
    return false;
}

int main() {
    int T; scanf("%d", &T); 
    while (T--) {
        scanf("%d %d", &gr, &gc);
        for (int i = 0; i < gr; ++i) scanf("%s", g[i]);
        scanf("%d %d", &pr, &pc);
        for (int i = 0; i < pr; ++i) scanf("%s", p[i]);
        bool res = search();
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
