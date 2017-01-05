#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Based on 139-WordBreak, dp + dfs
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return {};
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> canBreak(n+1, false); // canBreak[i] means s[0...i-1] can be broken
        canBreak[0] = true;
        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] means s[i...j] can be broken
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.count(s.substr(j, i-j))) {
                    canBreak[i] = true;
                    dp[j][i-1] = true;
                }
            }
        }
        vector<string> res, path;
        if (canBreak[n]) dfs(s, 0, dp, path, res);
        return res;
    }
    
    void dfs(string& s, int start, vector<vector<bool>>& dp, vector<string>& path, vector<string>& res) {
        if (start == (int)s.size()) {
            string r = path[0];
            for (int i = 1; i < (int)path.size(); ++i) r += " " + path[i];
            res.push_back(r);
            return;
        }
        for (int i = start; i < (int)s.size(); ++i) {
            if (dp[start][i]) {
                path.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, dp, path, res);
                path.pop_back();
            }
        }
    }
};


int main() {
    return 0;
}

