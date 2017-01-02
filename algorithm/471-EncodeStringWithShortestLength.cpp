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
                    string left = dp[i][k];
                    string right = dp[k+1][j];
                    if (left.size()+right.size() < dp[i][j].size()) dp[i][j] = left+right;
                }
                string co = collapse(s, i, j, dp);
                if (co.size() < dp[i][j].size()) dp[i][j] = co;
            }
        }
        return dp[0][n-1];
    }

    // find repeated pattern in s[i:j]
    // this method is learnt from 459-RepeatedSubstringPattern solution 3
    string collapse(string& s, int i, int j, vector<vector<string>>& dp) {
        string t = s.substr(i, j-i+1);
        auto pos = (t+t).find(t, 1);
        if (pos >= t.size()) return t;
        return to_string(t.size()/pos) + '[' + dp[i][i+pos-1] + ']';
    }
};


int main() {
    Solution s;
    cout << s.encode("abbbabbbcabbbabbbc") <<endl;
    return 0;
}
