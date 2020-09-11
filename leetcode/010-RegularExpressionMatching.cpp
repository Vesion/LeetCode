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
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i < m+1; ++i) dp[i][0] = false;
        for (int j = 1; j < n+1; ++j)
            dp[0][j] = p[j-1] == '*' && j >= 2 && dp[0][j-2];

        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (p[j-1] != '*') {
                    dp[i][j] = (p[j-1] == '.' || s[i-1] == p[j-1]) &&
                               (dp[i-1][j-1]);
                } else {
                    // a* for empty or aa*
                    dp[i][j] = (j >= 2) &&
                               (dp[i][j-2] ||
                                (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')));
                }
            }
        }
        return dp[m][n];
    }
};


int main() {
    return 0;
}

