#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false); // dp[i] == true means s[0...i) can be broken
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j] && wordDict.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    return 0;
}

