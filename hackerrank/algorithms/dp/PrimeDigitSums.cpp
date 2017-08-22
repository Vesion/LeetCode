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
const int MAXN = 4e5+5;
const int MOD = 1e9+7;
ll res[MAXN];
ll dp[2][10][10][10][10];
int Q, N;

// 2 3 5 7 11 13 17 19 23 29 31 37 41 43
bool is_prime[45];
void get_prime() {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < 45; ++i) {
        if (is_prime[i]) {
            for (int j = i+i; j < 45; j += i) is_prime[j] = false;
        }
    }
}
const vector<int> prime3[19] = {
    /*  0 */ { 2, 3, 5, 7, },
    /*  1 */ { 1, 2, 4, 6, },
    /*  2 */ { 0, 1, 3, 5, 9, },
    /*  2 */ { 0, 2, 4, 8, },
    /*  4 */ { 1, 3, 7, 9, },
    /*  5 */ { 0, 2, 6, 8, },
    /*  6 */ { 1, 5, 7, },
    /*  7 */ { 0, 4, 6, },
    /*  8 */ { 3, 5, 9, },
    /*  9 */ { 2, 4, 8, },
    /* 10 */ { 1, 3, 7, 9, },
    /* 11 */ { 0, 2, 6, 8, },
    /* 12 */ { 1, 5, 7, },
    /* 13 */ { 0, 4, 6, },
    /* 14 */ { 3, 5, 9, },
    /* 15 */ { 2, 4, 8, },
    /* 16 */ { 1, 3, 7, },
    /* 17 */ { 0, 2, 6, },
    /* 18 */ { 1, 5, },
};

int main() {
    get_prime();
    res[1] = 9, res[2] = 90, res[3] = 303, res[4] = 280; // pre calculated
    For (a, 0, 10) if (a != 0)
        For (b, 0, 10)
            For (c, 0, 10) if (is_prime[a+b+c])
                For (d, 0, 10) if (is_prime[b+c+d] && is_prime[a+b+c+d])
                    dp[0][a][b][c][d] = 1;

    For (i, 4, MAXN) {
        ll r = 0;
        For (a, 0, 10)
            For (b, 0, 10)
                for (int c : prime3[a+b])
                    for (int d : prime3[b+c]) {
                        if (!dp[i&1][a][b][c][d]) continue;
                        ll t = dp[i&1][a][b][c][d] % MOD;
                        dp[i&1][a][b][c][d] = 0;
                        for (int e : prime3[c+d]) {
                            if (!is_prime[b+c+d+e]) continue;
                            if (!is_prime[a+b+c+d+e]) continue;
                            dp[(i&1)^1][b][c][d][e] += t;
                            r += t;
                        }
                    }
        res[i+1] = r % MOD;
    }

    cin >> Q;
    while (Q--) {
        cin >> N;
        cout << res[N] << endl;
    }
    return 0;
}
