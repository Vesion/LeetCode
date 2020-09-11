#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dfs
class Solution1 {
public:
    vector<string> m;
    vector<string> res;

    vector<string> letterCombinations(string digits) {
        m.resize(10);
        m[2] = "abc"; m[3] = "def"; m[4] = "ghi";
        m[5] = "jkl"; m[6] = "mno"; m[7] = "pqrs";
        m[8] = "tuv"; m[9] = "wxyz";
        string path;
        dfs(digits, 0, path);
        return res;
    }

    void dfs(const string& d, const int i, string& path) {
        if (i == d.size()) {
            if (!path.empty()) res.push_back(path);
            return;
        }
        for (const char c : m[d[i]-'0']) {
            path.push_back(c);
            dfs(d, i+1, path);
            path.pop_back();
        }
    }
};

// iterative
class Solution {
public:
    vector<string> letterCombinations(string s) {
        if (s.empty()) return {};
        vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res({""});
        for (int i = 0; i < (int)s.size(); ++i) {
            vector<string> t;
            int d = s[i]-'0';
            for (string& r : res) {
                for (char& c : m[d]) t.push_back(r+c);
            }
            res = t;
        }
        return res;
    }
};

int main() {
    return 0;
}
