#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 10 * (1<<20);
char s[MAXN];
int c[26];
int n;

bool solve() {
    memset(c, 0, sizeof c);
    int cur = -1, prev1 = -1, prev2 = -1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && s[i] != s[i-1]) {
            prev2 = prev1;
            prev1 = cur;
            cur = s[i]-'a';
            c[cur] = 1;
        } else {
            cur = s[i]-'a';
            ++c[cur];
        }

        if (cur == prev1+1 && prev1 == prev2+1 && c[cur] >= c[prev1] && c[cur] <= c[prev2]) return true;
    }
    return false;
}

int main() {
    int T; scanf("%d", &T); 
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s);
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
