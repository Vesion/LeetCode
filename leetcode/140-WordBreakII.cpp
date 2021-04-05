#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Based on 139-WordBreak, dp + dfs
class Solution {
public:
    int n;
    vector<vector<bool>> dp;
    vector<string> res;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        vector<bool> can(n+1, false);
        can[0] = true;
        dp.resize(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (can[j] && m.count(s.substr(j, i-j+1))) {
                    can[i+1] = true;
                    dp[j][i] = true;
                }
            }
        }
        if (!can[n]) return {};
        string path;
        dfs(s, 0, path);
        return res;
    }

    void dfs(const string& s, int start, string& path) {
        if (start == n) {
            path.pop_back();  // remove tail space
            res.push_back(path);
            return;
        }
        for (int i = start; i < n; ++i) {
            if (dp[start][i]) {
                int t = path.size();
                path += s.substr(start, i-start+1) + " ";
                dfs(s, i+1, path);
                path.resize(t);  // backtracking
            }
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
