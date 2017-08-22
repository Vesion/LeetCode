#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};


// Solution 2 : math, C(m+n-2, m-1)
class Solution_2 {
public:
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        long long dividend = 1, divisor = 1;
        for (int i = 1; i <= m-1; ++i) divisor *= i; // (m-1)!
        for (int i = n; i <= m+n-2; ++i) dividend *= i; // (n)*(n+1)*...*(m+n-2)
        return dividend / divisor;
    }
};


int main() {
    return 0;
}
