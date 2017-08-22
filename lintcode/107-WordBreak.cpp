#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

// Solution 1 : naive dfs, TLE!
class Solution_1 {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() && dict.empty()) return true;
        if (s.empty() || dict.empty()) return false;
        if (dict.count(s)) return true;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            if (wordBreak(s1, dict) && wordBreak(s2, dict)) return true;
        }
        return false;
    }
};


// Solution 2 : dp
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> dp(n+1, false); // dp[i] is true means prefix substring length i can be broken
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j] && dict.count(s.substr(j, i-j))) {
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
    unordered_set<string> dict = {"lint", "code"};
    cout << s.wordBreak("lintcode", dict) << endl;
    return 0;
}
