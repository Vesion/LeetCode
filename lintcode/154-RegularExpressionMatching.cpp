#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : recursively
class Solution_1 {
public:
    bool isMatch(const char *s, const char *p) {
        // if p is empty, s must be empty
        if (strlen(p) == 0)
            return strlen(s) == 0;

        // if p is x*, it matches empty or eat one character (x* -> xx*)
        if (*(p+1) == '*')
            return isMatch(s, p+2)
                || (strlen(s) != 0 && (*s == *p || *p == '.') && isMatch(s+1, p));

        // else, this character must be eaten
        else
            return strlen(s) != 0 && (*s == *p || *p == '.') && isMatch(s+1, p+1);
    }
};


// Solution 2 : dp

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s), n = strlen(p);
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j > 1 && p[j-1] == '*' && dp[0][j-2];

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    if (j == 1) dp[i][j] = i == 0; // in case of p is "*x"
                    else dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("bbabacccbcbbcaaab", "*a*b..b*b") <<endl;
    return 0;
}
