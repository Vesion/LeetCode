#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Caculate C(n, k)


// Solution 1 : DP, C(n, k) = C(n-1, k-1) + C(n-1, k)
// can get all C(i, j), i <= n, j <= k
const int MAXN = 1e3;
int C[MAXN][MAXN];
void combination_table() {
    memset(C, 0, sizeof C);
    for (int i = 0; i < MAXN; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
}

// Solution 2 : math
int combination(int n, int k) {
    long long dividend = 1, divisor = 1;
    for (int i = n; i >= n-k+1; --i) dividend *= i; // n * (n-1) * ... * (n-k+1)
    for (int i = k; i >= 1; --i) divisor *= i; // k!
    return dividend / divisor;
}


int main() {
    combination_table();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}
