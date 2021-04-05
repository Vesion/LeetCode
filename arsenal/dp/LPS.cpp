#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Longest palindromic subsequence (LPS)
// https://leetcode.com/problems/valid-palindrome-iii/
// https://leetcode.com/problems/longest-palindromic-subsequence/

// LPS(s) = LCS(s, reverse(s))
class Solution0 {
public:
    int longestPalindromeSubseq(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        return lcs(s, rs);
    }

    int lcs(const string& s1, const string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (int i = 0; i <= n1; ++i) dp[i][0] = 0;
        for (int j = 0; j <= n2; ++j) dp[0][j] = 0;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                if (s[i] == s[j]) dp[i][j] = i+1 == j ? 2 : dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

int main() {

}