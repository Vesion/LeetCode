#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : greedy, O(n)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char& c : t) {
            if (i == s.size()) break;
            if (c == s[i]) ++i;
        }
        return i == (int)s.size();
    }
};


// Solution 2 : dp, O(n^2)
class Solution_2 {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) dp[i][0] = false;
        for (int j = 1; j <= n; ++j) dp[0][j] = true;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (s[i-1] == t[j-1] && dp[i-1][j-1]) || dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};


int main() {
    return 0;
}

