#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
char s[MAXN];
ll suf[MAXN];

int main() {
    scanf("%s", s); 
    int N = strlen(s);
    for (int i = 1; i <= N; ++i) {
        int d = s[i-1]-'0';
        suf[i] = (suf[i-1]*10%MOD+d*(i-1)%MOD + d) % MOD;
    }
    ll res = 0;
    for (int i = 1; i <= N; ++i) res = (res + suf[i]) % MOD;
    cout << res << endl;
    return 0;
}
