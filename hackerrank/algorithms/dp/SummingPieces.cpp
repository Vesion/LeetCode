#include <cstdio> 
using namespace std;

typedef long long ll;

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int logN = 18;
const int inf = 1e9;
const int N = 1e6+5;

int n, dp[N], a[N], all[N], pre_all[N];

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    all[0] = pre_all[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if(i == 1) all[i] = 1;
        else all[i] = all[i-1] * 2LL % mod;
        pre_all[i] = (pre_all[i-1] + all[i]) % mod;
    }

    ll mul = 0, add = 0;

    for (int i = 1; i <= n; ++i) {
        mul = (mul + pre_all[i-1]) % mod;
        dp[i] = (2*dp[i-1] + (ll) add + mul * (ll) a[i] % mod) % mod;
        add = (add + (ll) a[i] * pre_all[i-1] % mod) % mod;;
    }
    printf("%d\n", dp[n]);

    return 0;
}

