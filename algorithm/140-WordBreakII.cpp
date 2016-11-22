#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Based on 139-WordBreak, dp + dfs
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        vector<vector<bool>> dps(n, vector<bool>(n, false)); // dps[i][j] == true, means s[i...j] can be broken
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j] && wordDict.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    dps[j][i-1] = true;
                }
            }
        }

        vector<string> res;
        vector<string> path;
        if (dp[n]) // skip over the large case
            dfs(s, 0, dps, path, res);
        return res;
    }

    void dfs(string& s, int cur, vector<vector<bool>>& dps, vector<string>& path, vector<string>& res) {
        if (cur == (int)s.size()) {
            string r = path[0];
            for (int i = 1; i < (int)path.size(); ++i) r += " " + path[i];
            res.push_back(r);
            return;
        }
        for (int i = cur; i < (int)s.size(); ++i) {
            if (dps[cur][i]) {
                path.push_back(s.substr(cur, i-cur+1));
                dfs(s, i+1, dps, path, res);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> w ={ "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    auto r = s.wordBreak(a, w);
    for (auto& e : r) cout << e << " " << endl;; cout << endl; 
    return 0;
}

