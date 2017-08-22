#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 10;
char g[MAXN][MAXN];
char s[MAXN*MAXN];
int r, c;
int l;


int main() {
    memset(g, 0, sizeof g);
    scanf("%s", s); 
    l = strlen(s);
    r = floor(sqrt(l)), c = floor(sqrt(l));
    if (r*c < l) ++c;
    if (r*c < l) ++r;
    for (int i = 0; i < l; ++i) g[i/c][i%c] = s[i];
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) if (g[i][j]) putchar(g[i][j]);
        if (j != c-1) putchar(' ');
    }
    return 0;
}
