#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : common dfs, O(n^3)
class Solution_1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    void dfs(string& s, int cur, vector<string>& path, vector<vector<string>>& res) {
        if (cur == (int)s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < (int)s.size(); ++i) {
            string sub = s.substr(cur, i-cur+1);
            if (i == cur || isPalindrome(sub)) {
                path.push_back(sub);
                dfs(s, i+1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s) {
        int left = 0, right = s.size()-1;
        while (left <= right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};


// Solution 2 : dp + dfs, O(n^2), use dp array to judge palindrome in O(1)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int i = n-1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                dp[i][j] = (s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1]));

        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, dp, path, res);
        return res;
    }

    void dfs(string& s, int cur, vector<vector<bool>>& dp, vector<string>& path, vector<vector<string>>& res) {
        if (cur == (int)s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < (int)s.size(); ++i) {
            if (dp[cur][i]) { // use dp O(1) to judge palindrome, instead of O(n) judge
                path.push_back(s.substr(cur, i-cur+1));
                dfs(s, i+1, dp, path, res);
                path.pop_back();
            }
        }
    }
};


int main() {
    Solution s;
    auto r = s.partition("aab");
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

