#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 1 : dfs-backtracking, TLE of course =.=
// only for understanding backtracking, bad performance
bool dfs(string &s1, string &s2, string &s3, int i, int j, int cur) {
    if (i == s1.size() && j == s2.size() && cur == s3.size())
        return true;
    if (s3[cur] == s1[i])
        if (dfs(s1, s2, s3, i+1, j, cur+1))
            return true;
    if (s3[cur] == s2[j])
        if (dfs(s1, s2, s3, i, j+1, cur+1))
            return true;
    return false;    
}

bool isInterleave_dfs(string s1, string s2, string s3) {
    return dfs(s1, s2, s3, 0, 0, 0);
}

// Solution 2 : dp, O(n*m) time, O(n*m) space
// dp[i][j]表示s1[0...i]和s2[0...j]能匹配s3[0...i+j]
// 所以，如果当前字符s1能匹配s3则dp[i][j]=dp[i-1][j]，如果s2能匹配s3则dp[i][j]=dp[i][j-1]
bool isInterleave_dp(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n3 != n1 + n2) return false;
    vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, true));
    for (int i = 1; i <= n1; ++i)
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    for (int j = 1; j <= n2; ++j)
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1])
                    || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[n1][n2];
}

int main() {
    cout << isInterleave_dfs("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << isInterleave_dfs("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << isInterleave_dp("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << isInterleave_dp("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}
