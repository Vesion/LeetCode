#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp + backtracking, O(n^2), use dp array to judge palindrome in O(1)
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<bool>> dp;
    int n;

    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.resize(n, vector<bool>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                if (s[i] == s[j]) dp[i][j] = i+1>j-1 || dp[i+1][j-1];
            }
        }
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

    void dfs(const string& s, int start, vector<string>& path) {
        if (start == n) {
            if (!path.empty()) res.push_back(path);
            return;
        }
        for (int i = start; i < n; ++i) {
            if (dp[start][i]) {
                path.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, path);
                path.pop_back();
            }
        }
    }
};


int main() {
    return 0;
}
