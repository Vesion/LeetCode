#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                if (s[i] == s[j] && (len <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};


int main() {
}
