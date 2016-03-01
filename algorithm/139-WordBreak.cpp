#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Solution 0 : dfs-backtracking, O(n^2) time, O(n) space, TLE!
bool dfs(string& s, unordered_set<string>& wordDict, int start, int n) {
    if (start == n) return true;
    for (int i = n-1; i >= start; --i) {
        string sub = s.substr(start, i-start+1);
        if (wordDict.find(sub) == wordDict.end()) continue;
        if (dfs(s, wordDict, i+1, n)) return true;
    }
    return false;
}

bool wordBreak_dfs(string s, unordered_set<string>& wordDict) {
    if (s.empty()) return wordDict.find(s) != wordDict.end();
    int n = s.size();
    return dfs(s, wordDict, 0, n);
}


// Solution 1 : dp, O(n^2) time, O(n) space
// similiar to 097
// dp[i] means that s[0...i] can be broken, dp[i] = {dp[j] && s[j+1...i] in wordDict, 0<=j< i}.
bool wordBreak_dp(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true; // empty string can be broken
    for (int i = 1; i <= n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}


int main() {
    unordered_set<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    //unordered_set<string> wordDict = {"leet", "code"};
    //string s = "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode";
    //cout << wordBreak_dfs(s, wordDict) << endl;
    cout << wordBreak_dp(s, wordDict) << endl;
    return 0;
}
