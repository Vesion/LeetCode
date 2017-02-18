#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp + backtracking, O(n^2), use dp array to judge palindrome in O(1)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                dp[i][j] = (s[i] == s[j]) && (i+1 == j || dp[i+1][j-1]);
            }
        }
        
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, dp, path, res);
        return res;
    }
    
    void dfs(string& s, int start, vector<vector<bool>>& dp, vector<string>& path, vector<vector<string>>& res) {
        if (start == (int)s.size()) {
            res.push_back(path);
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
