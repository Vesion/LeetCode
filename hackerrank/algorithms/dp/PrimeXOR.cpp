#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 4505;
const int MAXP = (1<<13)+5; // 8197
const int MOD = 1e9+7;
int c[MAXN];
ll dp[1005][MAXP];
int N;

bool is_prime[MAXP];
void get_prime_table_Er() {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < MAXP; ++i) {
        if (is_prime[i]) {
            for (int j = i+i; j < MAXP; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    get_prime_table_Er();
    int T; cin >> T;
    while (T--) {
        memset(dp, 0, sizeof dp);
        memset(c, 0, sizeof c);
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            c[a]++;
        }
        vector<int> a;
        for (int i = 3500; i < MAXN; ++i) if (c[i]) a.push_back(i);
        int M = a.size();

        dp[0][0] = 1;
        for (int i = 0; i < M; ++i) { // 1000
            int x = a[i];
            for (int j = 0; j < MAXP; ++j) { // 10000
                dp[i+1][x^j] = (dp[i+1][x^j] + (dp[i][j]*((c[x]+1)/2))%MOD) % MOD; // take out odd number of a[i]
                dp[i+1][j] = (dp[i+1][j] + (dp[i][j]*((c[x]/2)+1))%MOD) % MOD; // take out even number of a[i]
            }
        }

        ll res = 0;
        for (int j = 0; j < MAXP; ++j) {
            if (is_prime[j]) res = (res + dp[M][j]) % MOD;
        }
        cout << res << endl;
    }
    return 0;
}
