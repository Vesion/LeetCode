#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// similar to generate all subsets

// Solution 1 : backtracking
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(word, 0, 0, "", res);
        return res;
    }
    
    void dfs(string& s, int start, int abbr, string path, vector<string>& res) {
        if (start == (int)s.size()) {
            if (abbr) path += to_string(abbr);
            res.push_back(path);
            return;
        }
        dfs(s, start+1, abbr+1, path, res); // abbreviate it
        dfs(s, start+1, 0, path + (abbr ? to_string(abbr) : "") + s[start], res); // not abbreviate it
    }
};


// Solution 2 : bitmap
class Solution_2 {
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty()) return {""};
        int n = 1 << word.size();
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            string r;
            int mask = i, c = 0;
            for (int j = 0; j < (int)word.size(); ++j) {
                if (mask&1) ++c;
                else {
                    if (c) r += to_string(c);
                    r += word[j];
                    c = 0;
                }
                mask >>= 1;
            }
            if (c) r += to_string(c);
            res[i] = r;
        }
        return res;
    }
};


int main() {
    return 0;
}
