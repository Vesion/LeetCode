#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : top-down
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty(); // terminate condition
        if (p[1] == '*') 
            return (isMatch(s, p.substr(2)) // x* can match empty string
                || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p))); // or match at least one character x* -> xx*
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        
    }
};


// Solution 2 : bottom-up, dp
class Solution_dp {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));

        dp[0][0] = true;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = false;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j > 1 && p[j-1] == '*' && dp[0][j-2]; // if match empty

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')); // empty or x* -> xx*
                else
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                
            }
        }
        return dp[m][n];
    }
};


int main() {
    return 0;
}

