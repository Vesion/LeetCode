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
    vector<string> removeInvalidParentheses(string s) {
        int lefts = 0, rights = 0;
        for (char c : s) {
            if (c == '(') ++lefts;
            else if (c == ')') {
                if (lefts > 0) --lefts;
                else ++rights;
            }
        }

        unordered_set<string> res;
        dfs(s, 0, lefts, rights, 0, "", res);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(string& s, int start, int lefts, int rights, int pairs, string path, unordered_set<string>& res) {
        if (start == (int)s.size()) {
            if (lefts == 0 && rights == 0 && pairs == 0) res.insert(path);
            return;
        }

        char c = s[start];
        if (c == '(') {
            if (lefts > 0) dfs(s, start+1, lefts-1, rights, pairs, path, res); // if there are still invalid lefts, remove this one
            dfs(s, start+1, lefts, rights, pairs+1, path+c, res); // keep this left to form a pair
        }
        else if (c == ')') {
            if (rights > 0) dfs(s, start+1, lefts, rights-1, pairs, path, res); // if there are still invalid rights, remove this one
            if (pairs > 0) dfs(s, start+1, lefts, rights, pairs-1, path+c, res); // keep this right to eliminate a pair
        }
        else
            dfs(s, start+1, lefts, rights, pairs, path+c, res);
    }
};



// Solution 2 : BFS, much slower
// Similar to brute force, we extend states by remove a left or right level by level, and check if they are valid. O(2^n) time.
class Solution_2 {
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
    auto r = s.removeInvalidParentheses(")d))");
    cout << r.size() << endl;
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

