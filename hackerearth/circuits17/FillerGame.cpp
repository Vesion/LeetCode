#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <unordered_map> 
#include <bitset> 
using namespace std;

const int MAXN = (1<<20)+10;
int memo[MAXN];
char s[25];
int n, m, q;

bool check(int state, int i, int j) {
    if (((state>>(i*m+j))&1) == 0) {
        if (i-1 >= 0 && (((state>>((i-1)*m+j))&1) == 0)) return true;
        if (j-1 >= 0 && (((state>>((i)*m+j-1))&1) == 0)) return true;
        if (i+1 < n && (((state>>((i+1)*m+j))&1) == 0)) return true;
        if (j+1 < m && (((state>>((i)*m+j+1))&1) == 0)) return true;
    }
    return false;
}

bool dfs(int state) {
    if (memo[state] != -1) return memo[state];
    bool res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (check(state, i, j)) {
                res |= !dfs(state|(1<<(i*m+j)));
            }
        }
    }
    memo[state] = res;
    return res;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    memset(memo, -1, sizeof memo);
    while (q--) {
        int state = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < m; ++j) state |= ((s[j]-'0')<<(i*m+j));
        }
        printf("%d\n", !dfs(state));
    }
    return 0;
}
