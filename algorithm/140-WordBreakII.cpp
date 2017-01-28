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
        if (s.empty() || wordDict.empty()) return {};
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> canBreak(n+1, false);
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        canBreak[0] = true;
        for (int j = 1; j <= n; ++j) {
            for (int i = j-1; i >= 0; --i) {
                if (canBreak[i] && dict.count(s.substr(i, j-i))) {
                    canBreak[j] = true;
                    dp[i][j-1] = true;
                }
            }
        }
        vector<string> res;
        if (canBreak[n]) dfs(s, 0, dp, "", res);
        return res;
    }
    
    void dfs(string& s, int start, vector<vector<bool>>& dp, string path, vector<string>& res) {
        if (start == (int)s.size()) {
            path.pop_back();
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)s.size(); ++i) {
            if (dp[start][i]) dfs(s, i+1, dp, path+s.substr(start, i-start+1)+" ", res);
        }
    }
};


int main() {
    return 0;
}
