#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 5e5+5;
int s[MAXN];
int c[4];
int n;

int solve() {
    int i = 0, j = 0;
    int res = n;
    while (j < n) {
        c[s[j++]]--;
        while (c[0]<=0 && c[1]<=0 && c[2]<=0 && c[3]<=0) {
            res = min(res, j-i);
            c[s[i++]]++;
        }
    }
    return res;
}

int main() {
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) {
        char t = getchar();
        if (t == 'A') s[i] = 0; else if (t == 'C') s[i] = 1; else if (t == 'T') s[i] = 2; else s[i] = 3;
        c[s[i]]++;
    }
    for (int i = 0; i < 4; ++i) c[i] = max(0, c[i]-n/4);
    printf("%d\n", solve());
    return 0;
}
