#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;
int N, R, C;
int go[8][2] = {{-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}};

struct Matrix {
    ll a[64][64];
    Matrix() { memset(a, 0, sizeof a); }

    Matrix operator* (const Matrix other) const {
        Matrix res;
        for (int i = 0; i < 64; ++i) 
            for (int j = 0; j < 64; ++j)
                for (int k = 0; k < 64; ++k) res.a[i][j] = (res.a[i][j]+a[i][k]*other.a[k][j]%MOD)%MOD;
        return res;
    }

    Matrix operator^ (int n) const {
        Matrix t = (*this), res;
        for (int i = 0; i < 64; ++i) res.a[i][i] = 1;
        while (n) {
            if (n&1) res = res * t;
            t = t*t;
            n >>= 1;
        }
        return res;
    }
} T;

void init() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int id = i*8+j;
            for (int d = 0; d < 8; ++d) {
                int ni = i+go[d][0], nj = j+go[d][1];
                if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8) continue;
                int nid = ni*8+nj;
                T.a[id][nid] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> R >> C;
    init();
    T = T^N;
    --R, --C;
    int id = R*8+C;
    ll res = 0;
    for (int i = 0; i < 64; ++i) res = (res + T.a[i][id]) % MOD;
    cout << res << endl;
    return 0;
}

