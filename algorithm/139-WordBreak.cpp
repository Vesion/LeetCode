#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) return false;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false); // dp[i] means s[0...i) can be broken
        dp[0] = true;
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (dp[i] && dict.count(s.substr(i, j-i+1))) {
                    dp[j+1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


int main() {
    return 0;
}

