#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DP, for a substring s, we can either:
//      1. not encode it at all
//      2. encode it as one part k[...]
//      3. encode it as multiple parts (in which case we can somewhere split it into two subproblems)
// We need the shortest one of three cases
class Solution {
public:
    vector<vector<string>> dp;

    string encode(string s) {
        int n = s.size();
        dp = vector<vector<string>>(n, vector<string>(n, ""));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;

                // 1. not encode
                dp[i][j] = s.substr(i, len);

                // 2. try to encode as k[...]
                string co = collapse(s, i, len);
                if (co.size() < dp[i][j].size()) dp[i][j] = co;

                // 3. split
                for (int k = i; k < j; ++k) {
                    if (dp[i][k].size() + dp[k+1][j].size() < dp[i][j].size())
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                }
            }
        }
        return dp[0][n-1];
    }

    string collapse(const string& s, int i, int len) {
        string t = s.substr(i, len);
        auto pos = (t+t).find(t, 1);
        if (pos >= t.size()) return t;
        int num = t.size() / pos;
        return to_string(num) + "[" + dp[i][i+pos-1] + "]";
    }
};


int main() {
    Solution s;
    cout << s.encode("abbbabbbcabbbabbbc") <<endl;
    return 0;
}
