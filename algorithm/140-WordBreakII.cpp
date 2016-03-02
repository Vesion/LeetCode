#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Solution 1 : dfs-backtracking
// trivial dfs must be TLE, here we use a bool vector to prune
void dfs(vector<string>& result, vector<string>& path, string& s, int cur, unordered_set<string>& wordDict, vector<bool>& invalid) {
    if (invalid[cur]) return; // do not need to process from this cur, prune
    if (cur == s.size()) {
        string sen = path[0];
        for (int i = 1; i < path.size(); ++i) sen += (" " + path[i]);
        result.push_back(sen);
        return;
    }
    int origin_len = result.size();
    for (int i = cur; i < s.size(); ++i) {
        string word = s.substr(cur, i-cur+1);
        if (wordDict.count(word)) {
            path.push_back(word);
            dfs(result, path, s, i+1, wordDict, invalid);
            path.pop_back();
        }
    }
    if (result.size() == origin_len) // if after processing from cur, the size of result doesn't change, set this cur as invalid
        invalid[cur] = true;
}

vector<string> wordBreak_dfs(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<string> result;
    vector<string> path;
    vector<bool> invalid(n, false);
    dfs(result, path, s, 0, wordDict, invalid);
    return result;
}


// Solution 2 : dp + dfs
// 在139的基础上，用一个二位数组记录下所有合法的token，最后用dfs生成所有path即可
void dfs(vector<string>& result, vector<string>& path, string& s, int end, vector<vector<bool>>& dps) {
    if (end == 0) {
        int n = path.size();
        string temp = path[n-1];
        for (int i = n-2; i >= 0; --i) temp += (" " + path[i]);
        result.push_back(temp);
    }
    for (int i = 0; i < end; ++i) {
        if (dps[end][i]) {
            path.push_back(s.substr(i, end-i));
            dfs(result, path, s, i, dps);
            path.pop_back();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n+1, false);
    vector<vector<bool>> dps(n+1, vector<bool>(n, false)); // dps[i][j] means that s[j...i] can be a valid token in wordDict
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                dp[i] = true;
                dps[i][j] = true;
            }
        }
    }

    vector<string> result;
    vector<string> path;
    dfs(result, path, s, n, dps);
    return result;
}

int main() {
    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    string s = "catsanddog";
    //auto result = wordBreak(s, wordDict);
    auto result = wordBreak_dfs(s, wordDict);
    for (auto i : result)
        cout << i << endl;
    return 0;
}
