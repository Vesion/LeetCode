#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct Matrix {
    const static int N = 2;
    int a[N][N];
    Matrix() { memset(a, 0, sizeof a); }

    Matrix operator* (const Matrix other) const {
        Matrix res;
        for (int i = 0; i < N; ++i) 
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k) res.a[i][j] += a[i][k]*other.a[k][j];
        return res;
    }

    Matrix operator^ (int n) const { // fast power(n)
        Matrix t = (*this), res;
        for (int i = 0; i < N; ++i) res.a[i][i] = 1;
        while (n) {
            if (n&1) res = res * t;
            t = t*t;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Matrix t;
    t.a[0][0] = 1, t.a[0][1] = 2;
    t.a[1][0] = 3, t.a[1][1] = 4;
    t = t^2;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) cout << t.a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
