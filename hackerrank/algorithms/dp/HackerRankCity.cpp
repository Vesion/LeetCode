#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
#define For(i,m,n) for (int (i) = (m); (i) < int(n); ++(i))
using ll = long long;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;
ll a[MAXN];
int N;

// s - sum of distances, result
// p - number of nodes
// h - sum of distances between nodes and corner
// l - diameter (the farthest distance of two nodes)

// new s = 16*a*p^2+12*p*h + 4*s + (6*a*p+4*h)*2
// new p = 4*p+2
// new h = 4*h + (8*a+3*l)*p + 3*a+2*l
// new l = 2*l + 3*a

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    ll s0 = 0, p0 = 1, h0 = 0, l0 = 0;
    ll s1, p1, h1, l1;
    for (int i = 0; i < N; ++i) {
        s1 = (16*a[i]*(p0*p0%MOD)%MOD + 12*(p0*h0%MOD)%MOD + 4*s0%MOD + ((6*a[i]*p0+4*h0)*2+a[i])%MOD) % MOD;
        p1 = (4*p0+2) % MOD;
        h1 = (4*h0%MOD + (8*a[i]+3*l0)*p0%MOD + 3*a[i] + 2*l0) % MOD;
        l1 = (2*l0 + 3*a[i]) % MOD;
        s0 = s1, p0 = p1, h0 = h1, l0 = l1;
    }
    cout << s0 << endl;
    return 0;
}
