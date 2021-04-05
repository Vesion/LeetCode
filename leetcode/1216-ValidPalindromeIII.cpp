#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Longest palindromic subsequence (LPS)
// LPS(s) = LCS(s, reverse(s))
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        return s.size() - lps(s) <= k;
    }

    int lps(const string& s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        return lcs(s, rs);
    }

    int lcs(const string& p, const string& q) {
        int m = p.size(), n = q.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
            if (p[i-1] == q[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
        return dp[m][n];
    }
};

int main() {

}
