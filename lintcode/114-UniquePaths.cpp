#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset> 
using namespace std;

// Solution 1 : dp[i][j] = dp[i-1][j] + dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[0][i] = 1;
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


// Solution 2 : formula, C(m+n, m), overflow
class Solution_f {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m > n) return uniquePaths(n, m);
        long long numerator = 1, denominator = 1;
        for (int i = n; i <= m+n-2; ++i) numerator *= i; // n * (n+1) * ... * (m-1+n-1)
        for (int i = 1; i <= m-1; ++i) denominator *= i; // (m-1)!
        cout << numerator << " " << denominator << endl;
        return numerator / denominator;
    }
};



int main() {
    Solution s;
    cout << s.uniquePaths(16, 16) << endl;

    Solution_f s2;
    cout << s2.uniquePaths(16, 16) << endl;
    return 0;
}
