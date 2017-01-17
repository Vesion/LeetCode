#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// interval dp
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                dp[i][j] = s.substr(i, len);
                for (int k = i; k < j; ++k) {
                    if (dp[i][k].size()+dp[k+1][j].size() < dp[i][j].size())
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                }
                string co = collapse(s, i, j, dp);
                if (co.size() < dp[i][j].size()) dp[i][j] = co;
            }
        }
        return dp[0][n-1];
    }

    // find repeated pattern in s[i:j]
    // this method: (t+t).find(t,1) < t.size()
    // is learnt from 459-RepeatedSubstringPattern solution 3
    string collapse(string& s, int i, int j, vector<vector<string>>& dp) {
        string t = s.substr(i, j-i+1);
        auto pos = (t+t).find(t, 1);
        if (pos >= t.size()) return t;

        // if s[i:j] is self-repeated, and its repeated pattern is s[i:p]
        // then s[i:j] can be encoded into n[dp[i][p]] 
        // because s[i:p] may have been encoded, so here must use dp[i][p]
        return to_string(t.size()/pos) + '[' + dp[i][i+pos-1] + ']';
    }
};


int main() {
    Solution s;
    cout << s.encode("abbbabbbcabbbabbbc") <<endl;
    return 0;
}
