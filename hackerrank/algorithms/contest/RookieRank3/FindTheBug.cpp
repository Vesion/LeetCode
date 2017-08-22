#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e3+5;
char a[MAXN][MAXN];
int n;
int r, c;

void solve() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (a[i][j] == 'X') { r = i; c = j; return; }
}

int main() {
    scanf("%d", &n);    
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    solve();
    printf("%d,%d\n", r, c);
    return 0;
}
