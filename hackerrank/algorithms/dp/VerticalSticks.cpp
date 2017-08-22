#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Expectation has linearity property, so
//      E(V(y1, y2, ..., yn)) = E(v1+v2+...+vn)

using ll = long long;
const int MAXN = 55;
int a[MAXN];
ll C[MAXN][MAXN];
int N;

void getC() {
    C[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i-1][j]+C[i-1][j-1];
    }
}

int main() {
    getC(); 
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> a[i];
        sort(a, a+N);
        double res = 0;
        for (int i = 0; i < N; ++i) {
            int s = 0;
            for (int j = 0; j < N; ++j) if (a[j] < a[i]) ++s;
            int g = N-s-1;
            for (int j = 1; j <= N; ++j) {
                for (int k = 0; k <= min(j-1, s); ++k) {
                    if (k == j-1) res += (double)(k+1)*C[s][k]/(N*C[N-1][k]); // len * P = (k+1) * ( (C[s][k] * k! * (N-1-k)! / N!) )
                    else res += (double)(k+1)*C[s][k]*g/(N*(N-1)*C[N-2][k]);  // len * P = (k+1) * ( (C[s][k] * k! * g * (N-2-k)! / N!) )
                }
            }
        }
        printf("%.2f\n", res);
    }
    return 0;
}
