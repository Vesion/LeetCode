#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp[i][j] = the number of distinct subsequences of s[0...j) which equal to t[0...i)
// fill dp row by row
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) dp[i][0] = 0;
        for (int j = 1; j <= n; ++j) dp[0][j] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1]; // dp[i][j] is at least dp[i][j-1], as if we haven't read s[j-1]
                if (t[i-1] == s[j-1]) dp[i][j] += dp[i-1][j-1]; // if t[i-1] == s[j-1], we can plus previous result of shorter t and s
            }
        }
        return dp[m][n];
    }
};


int main() {
    return 0;
}
