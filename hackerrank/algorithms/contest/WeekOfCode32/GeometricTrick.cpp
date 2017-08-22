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
char s[MAXN];
vector<int> a[MAXN];
bool vis[MAXN];
int n;

bool check(int i, int k) {
    if (s[i] == 'b' || s[k] == 'b' || s[i] == s[k]) return false;
    ll j = sqrt((ll)i * (ll)k); // here i*j must be a perfect square number
    return s[j] == 'b';
}

int main() {
    scanf("%d", &n);    
    scanf("%s", s+1);

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        for (int j = 1; i*j*j <= n; ++j) {
            a[i].push_back(i*j*j);
            vis[i*j*j] = true;
        }
    }

    int res = 0;
    for (int j = 1; j <= n; ++j) {
        int m = a[j].size();
        if (s[j] != 'b' || m < 2) continue;
        for (int i = 0; i < m; ++i) {
            for (int k = i+1; k < m; ++k) {
                if (check(a[j][i], a[j][k])) ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}
