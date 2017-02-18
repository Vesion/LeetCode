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
        vector<bool> canbreak(n+1, false);
        canbreak[0] = true;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (canbreak[i] && dict.count(s.substr(i, j-i+1))) {
                    canbreak[j+1] = true;
                    dp[i][j] = true;
                }
            }
        }
        if (!canbreak[n]) return {};
        vector<string> res;
        dfs(s, 0, dp, "", res);
        return res;
    }
    
    void dfs(string& s, int start, vector<vector<bool>>& dp, string path, vector<string>& res) {
        if (start == (int)s.size()) {
            path.pop_back();
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)s.size(); ++i) {
            if (dp[start][i]) dfs(s, i+1, dp, path + s.substr(start, i-start+1) + " ", res);
        }
    }
};


int main() {
    Solution s;
    vector<string> d = { "cat","cats","and","sand","dog" };
    string w = "catsanddog";
    auto r = s.wordBreak(w, d);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
