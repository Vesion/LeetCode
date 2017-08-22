#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set> 
using namespace std;

using ll = long long;
const int MAXN = 1000001;
bool prime[MAXN];
int p[MAXN];
int M = 0;
int N;
bool has[MAXN+1000];

void get_primes() {
    memset(prime, true, sizeof prime);
    memset(p, 0, sizeof p);
    for (ll i = 2; i <= MAXN; ++i) {
        if (prime[i]) p[M++] = i;
        for (int j = 0; j < M; ++j) {
            int t = i * p[j];
            if (t > MAXN) break;
            prime[t] = false;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int a = MAXN, b = MAXN;
    for (int i = 0; i < M; ++i) {
        if (p[i] > N) break;
        if (has[N-p[i]]) {
            if (N-p[i] < a) {
                a = N-p[i], b = p[i];
            }
        }
        has[p[i]] = true;
    }
    cout << a << " " << b << endl;
}

int main() {
    cin >> N; 
    get_primes();
    //for (int i = 0; i < M; ++i) cout << p[i] << " ";
    solve();
    return 0;
}
