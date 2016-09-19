#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : DP, compare the length of LCS and the length of s. TLE, MLE
class Solution_dp {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<char>> dp(m+1, vector<char>(n+1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (dp[i][j] == m) return true;
            }
        }
        return dp[m][n] == m;
    }
};


// Solution 1 : greedy, just go through t to match s
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < (int)t.size(); ++j)
            if (s[i] == t[j]) ++i;
        return i == (int)s.size();
    }

};


int main() {
    Solution s;
    cout << s.isSubsequence("agd", "abcdefg") << endl;;
    return 0;
}
