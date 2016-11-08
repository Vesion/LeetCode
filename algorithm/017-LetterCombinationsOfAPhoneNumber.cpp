#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string s) {
        if (s.empty()) return {};
        vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        vector<string> res;
        dfs(0, s, path, res, m);
        return res;
    }

    void dfs(int cur, string& s, string& path, vector<string>& res, vector<string>& m) {
        if (cur == (int)s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < (int)m[s[cur]-'0'].size(); ++i) {
            path.push_back(m[s[cur]-'0'][i]);
            dfs(cur+1, s, path, res, m);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    return 0;
}

