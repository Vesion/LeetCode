#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 505;
char s[MAXN][MAXN];
int t[MAXN][MAXN];
int m, n;

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%s", s[i]);
    memset(t, -1, sizeof t);

    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j1 = 0; j1 < n; ++j1) {
            int marsh = s[i][j1] == 'x';
            for (int j2 = j1+1; j2 < n; ++j2) {
                marsh += s[i][j2] == 'x';
                if (s[i][j1] == 'x' || s[i][j2] == 'x') t[j1][j2] = -1;
                else if (marsh == 0 || t[j1][j2] >= 0) ++t[j1][j2]; 
                if (marsh == 0 && t[j1][j2]) {
                    res = max(res, 2*(j2-j1+t[j1][j2]));
                }
            }
        }
    }

    if (res == 0) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}

