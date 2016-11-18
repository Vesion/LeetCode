#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// s2 is a scramble of s1 must meet:
//
// s1 : |****|#########|   or  s1 : |****|#########|
// s2 : |****|#########|       s2 : |#########|****|


// Solution 1 : recursive
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        vector<int> count(128, 0);
        int n= s1.size();
        for (int i = 0; i < n; ++i) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int c : count) if (c != 0) return false;

        for (int l = 1; l <= n-1; ++l) {
            if (isScramble(s1.substr(0, l), s2.substr(0, l)) && isScramble(s1.substr(l), s2.substr(l))) return true;
            if (isScramble(s1.substr(0, l), s2.substr(n-l)) && isScramble(s1.substr(l), s2.substr(0, n-l))) return true;
        }
        return false;
    }
};


// Solution 2 : dp, O(n^4) time
// dp[l][i][j] = true, means s1[i...i+l-1] is a scramble of s2[j...j+l-1]
class Solution_2 {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool dp[n+1][n][n];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[1][i][j] = (s1[i] == s2[j]);

        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n-l; ++i) {
                for (int j = 0; j <= n-l; ++j) {
                    dp[l][i][j] = false;
                    for (int k = 1; k < l && !dp[l][i][j]; ++k) {
                        dp[l][i][j] |= (dp[k][i][j] && dp[l-k][i+k][j+k]);
                        dp[l][i][j] |= (dp[k][i+l-k][j] && dp[l-k][i][j+k]);
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};


int main() {
    Solution s;
    return 0;
}

