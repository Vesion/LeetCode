#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dfs-backtracking, trivial, O(n^2)
bool isPalindrome(string& s, int left, int right) {
    while (left < right && s[left] == s[right]) {
        ++left;
        --right;
    }
    return left >= right;
}

void dfs(vector<vector<string>>& result, vector<string>& path, string &s, int n, int start) {
    if (start == n) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < n; ++i) {
        if (isPalindrome(s, start, i)) {
            path.push_back(s.substr(start, i-start+1));
            dfs(result, path, s, n, i+1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition_dfs(string s) {
    vector<vector<string>> result;
    if (s.empty()) return result;
    vector<string> path;
    dfs(result, path, s, s.size(), 0);
    return result;
}


// Solution 2 : dp, O(n^2)
// dp[i][j]为真表示s[i...j]是回文，如果s[i] == s[j] and dp[i+1][j-1]，则dp[i][j]为真，即s[i...j]是回文，所以计算出dp就知道了所有的回文子串，那么在构造结果的时候就可以直接用dp来判断，而不需要每次用isPalindrome来判断了。

void search(vector<vector<string>>& result, vector<string>& path, string &s, int n, int start, vector<vector<bool>>& dp) {
    if (start == n) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < n; ++i) {
        if (dp[start][i]) {
            path.push_back(s.substr(start, i-start+1));
            search(result, path, s, n, i+1, dp);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition_dp(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) dp[i][i] = true; // single character is palindrome
    for (int i = n-1; i >= 0; --i) // dp[i][j] need dp[i+1][j-1]
        for (int j = i; j < n; ++j)
            if (s[i] == s[j] && ((i+1 > j-1) || dp[i+1][j-1])) dp[i][j] = true;
    
    vector<vector<string>> result;
    vector<string> path;
    search(result, path, s, s.size(), 0, dp);
    return move(result);
}

int main() {
    auto result = partition_dp("aab");
    for (auto & i : result) {
        for (auto & j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
