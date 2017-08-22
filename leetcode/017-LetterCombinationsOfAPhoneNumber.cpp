#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : recursive
class Solution {
public:
    vector<string> letterCombinations(string s) {
        if (s.empty()) return {};
        vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        dfs(s, 0, m, "", res);
        return res;
    }
    
    void dfs(string& s, int start, vector<string>& m, string path, vector<string>& res) {
        if (start == (int)s.size()) {
            res.push_back(path);
            return;
        }
        int i = s[start]-'0';
        if (m[i].empty()) dfs(s, start+1, m, path, res); // for case "012"
        else for (char& c : m[i]) dfs(s, start+1, m, path+c, res);
    }
};


// Solution 2 : iterative
class Solution_2 {
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
    Solution s;
    auto r = s.letterCombinations("012");
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
