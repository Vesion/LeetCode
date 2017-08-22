#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 205;
const int MAXX = 200005;
char s[MAXN];
int N, X, Y;

bool dfs(int p, int r) {
    if (p == N) {
        return r == Y;
    }
    if (s[p] != '?')
        return dfs(p+1, (r*10+(s[p]-'0'))%X);
    else {
        for (int i = 0; i < 10; ++i) {
            if (p == 0 && i == 0) continue;
            s[p] = i+'0';
            if (dfs(p+1, (r*10+i)%X)) return true;
            s[p] = '?';
        }
    }
    return false;
}

int main() {
    scanf("%s", s);
    scanf("%d %d", &X, &Y);
    N = strlen(s); 

    if (dfs(0, 0)) printf("%s\n", s);
    else printf("No solution\n");
    return 0;
}
