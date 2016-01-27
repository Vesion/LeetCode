#include <iostream>
using namespace std;

// Solution 1 : formula C(m-1+n-1, n-1)
int uniquePaths(int m, int n) {
    if (n < m) return uniquePaths(n, m);
    long long numerator = 1, denominator = 1;
    for (int i = n; i <= n+m-2; ++i)
        numerator *= i;
    for (int i = 1; i <= m-1; ++i)
        denominator *= i;
    return numerator / denominator;
}

// Solution 2 : DFS


// Solution 3 : DP, f[i][j] = f[i-1][j] + f[i][j-1]

int main() {
    cout << uniquePaths(12, 12);
    return 0;
}
