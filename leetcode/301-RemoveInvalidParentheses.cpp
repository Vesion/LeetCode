#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// Solution 1 : DFS, generate without invalid lefts and rights
class Solution {
public:
    unordered_set<string> res;
    vector<string> removeInvalidParentheses(string s) {
        // count invalid number of '('s and ')'s
        int lefts = 0, rights = 0;
        for (char c : s) {
            if (c == '(') ++lefts;
            else if (c == ')') {
                if (lefts > 0) --lefts;
                else ++rights;
            }
        }
        string path;
        dfs(s, 0, lefts, rights, 0, path);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(const string& s, int start, int lefts, int rights, int pairs, string& path) {
        if (start == s.size()) {
            if (lefts == 0 && rights == 0 && pairs == 0) res.insert(path);
            return;
        }
        char c = s[start];
        if (c == '(') {
            // if there are still redundant '('s, we can remove c
            if (lefts > 0) dfs(s, start+1, lefts-1, rights, pairs, path);
            // or use c to start a new pair
            path += c;
            dfs(s, start+1, lefts, rights, pairs+1, path);
            path.pop_back();
        } else if (c == ')') {
            // if there are still redundant ')'s, we can remove c
            if (rights > 0) dfs(s, start+1, lefts, rights-1, pairs, path);
            // or use c to end a pair
            if (pairs > 0) {
                path += c;
                dfs(s, start+1, lefts, rights, pairs-1, path);
                path.pop_back();
            }
        } else {
            path += c;
            dfs(s, start+1, lefts, rights, pairs, path);
            path.pop_back();
        }

    }
};


// Solution 2 : dfs, no preprocess, no duplicates, awesome! orz
// https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution
class Solution_2 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(s, 0, 0, "()", res);
        return res;
    }

    // why we need last_remove? try this case "())())"
    void dfs(string s, int cur_start, int last_remove, string p, vector<string>& res) {
        int lefts = 0;
        for (int i = cur_start; i <(int)s.size(); ++i) {
            if (s[i] == p[0]) ++lefts;
            else if (s[i] == p[1]) --lefts;
            if (lefts >= 0) continue;
            for (int j = last_remove; j <= i; ++j)
                if (s[j] == p[1] && (j == last_remove || s[j-1] != p[1])) // if find consecutive ')'s, we remove the first one
                    dfs(s.substr(0, j)+s.substr(j+1), i, j, p, res);
            return;
        }
        reverse(s.begin(), s.end());
        if (p[0] == '(') dfs(s, 0, 0, ")(", res);
        else res.push_back(s);
    }
};


// Solution 3 : BFS, much slower
// Similar to brute force, we extend states by remove a left or right level by level, and check if they are valid. O(2^n) time.
class Solution_3 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);

        bool found = false;
        while (!q.empty()) {
            string t = q.front(); q.pop();
            if (isValid(t)) {
                res.push_back(t);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < (int)t.size(); ++i) {
                if (t[i] != '(' && t[i] != ')') continue;
                string nextt = t.substr(0, i) + t.substr(i+1);
                if (!visited.count(nextt)) {
                    q.push(nextt);
                    visited.insert(nextt);
                }
            }
        }
        return res;
    }

    bool isValid(string& s) {
        int lefts = 0;
        for (char c : s) {
            if (c == '(') ++lefts;
            else if (c == ')') {
                if (lefts-- == 0) return false;
            }
        }
        return lefts == 0;
    }
};

int main() {
    Solution_2 s;
    auto r = s.removeInvalidParentheses("())())");
    cout << r.size() << endl;
    for (auto& e : r) cout << e << " "; cout << endl;
    return 0;
}

