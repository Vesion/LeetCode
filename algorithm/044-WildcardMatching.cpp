#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 010-RegularExpressionMatching, recursive and dp solution

// Solution 1 : recursive, TLE
class Solution_1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[0] == '*')
            return isMatch(s, p.substr(1)) || (!s.empty() && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '?') && isMatch(s.substr(1), p.substr(1));

    }
};


// Solution 2 : dp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) 
            dp[i][0] = false;
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') dp[0][j] = true;
            else break;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j]; // empty or * -> x*
                else
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("abbabaabaaababbabbbaaaaba","a*******b");
    return 0;
}

