#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Longest Common Subsequence
// f[i][j] = f[i-1][j-1]+1               if s1[i] == s2[j]
//           max(f[i-1][j], f[i][j-1])   if s1[i] != s2[j]
int longestCommonSubsequence(string s1, string s2) {
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

string LCS_print(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1));
    vector<vector<int>> direct(n1+1, vector<int>(n2+1)); // 1 for left-up, 2 for up, 3 for left;
    for (int i = 0; i <= n1; ++i) {
        dp[i][0] = 0;
        direct[i][0] = 0;
    }
    for (int j = 0; j <= n2; ++j) {
        dp[0][j] = 0;
        direct[0][j] = 0;
    }
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                direct[i][j] = 1;
            }
            else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    direct[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j-1];
                    direct[i][j] = 3;
                }
            }
        }
    }
    string lcs = "";
    for (int i = n1, j = n2; direct[i][j] != 0; ) {
        if (direct[i][j] == 1) {
            lcs = s1[i-1] + lcs;
            //lcs = s2[j-1] + lcs; // same with above
            --i; --j;
        } else if (direct[i][j] == 2) {
            --i;
        } else {
            --j;
        }
    }
    return lcs;
}


// Differenct with 'Longest Common Subsequence' problem
// DP Solution, O(m*n):
//      First find the longest common suffix of all pairs of prefixes of the strings:
//          LCSuffix(i, j) = LCSuffix(i-1, j-1) + 1     if A[i] == B[j]
//                           0                          if A[i] != B[j]
//      Then the longest common substring is the maximal of these longest common suffixes:
//          LCSubstr(A, B) = max{ LCSuffix(i, j) }
int longestCommonSubstring(string A, string B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> lcsuffix(m+1, vector<int>(n+1, 0));
    int lcsubstr = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            lcsuffix[i][j] = (A[i-1] == B[j-1] ? lcsuffix[i-1][j-1]+1 : 0);
            lcsubstr = max(lcsubstr, lcsuffix[i][j]);
        }
    }
    return lcsubstr;
} 


int main() {
    cout << longestCommonSubsequence("123", "a1b2c3") << endl;
    cout << LCS_print("ab23t", "a1b2c3") << endl;
    cout << longestCommonSubstring("abcd", "afbced") << endl;
    return 0;
}
