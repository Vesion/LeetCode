#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp
// similar to 516-LongestPalindromicSubsequence
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; ++i) dp[i][i] = 0;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                if (s[i] == s[j]) {
                    dp[i][j] = len > 2 ? dp[i+1][j-1] : 0;
                } else {
                    dp[i][j] = len > 2 ? dp[i+1][j-1]+2 : 2;
                    dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j-1])+1);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
}
