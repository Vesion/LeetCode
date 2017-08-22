#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 1e5+5;
char s[MAXN];
int n, k;

int solve() {
    if (n == 1) { if (k) s[0] = '9'; return 1; }

    int m = 0;
    for (int i = 0; i < n/2; ++i) if (s[i] != s[n-i-1]) ++m;
    if (m > k) return 0;

    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n-i-1]) {
            if (s[i] == '9' || s[n-i-1] == '9') {
                --k;
                s[i] = s[n-i-1] = '9';
            } else {
                if (k-m >= 1) {
                    k -= 2;
                    s[i] = s[n-i-1] = '9';
                } else {
                    --k;
                    s[i] = s[n-i-1] = max(s[i], s[n-i-1]);
                }
            }
            --m;
        } else {
            if (s[i] != '9' && k-m >= 2) {
                s[i] = s[n-i-1] = '9';
                k -= 2;
            }
        }
    }
    if (k && (n&1)) s[n/2] = '9';
    return 1;
}

int main() {
    cin >> n >> k; 
    scanf("%s", s);
    int r = solve();
    if (r) printf("%s\n", s); else printf("-1\n");
    return 0;
}
