#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// similar to generate all subsets
// generate path, abbreviate current character or not

// Solution 1 : backtracking
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty()) return {""};
        vector<string> res;
        dfs(word, 0, 0, "", res);
        return res;
    }
    
    void dfs(string& word, int start, int abbr, string path, vector<string>& res) {
        if (start == (int)word.size()) {
            if (abbr) path += to_string(abbr);
            res.push_back(path);
            return;
        }
        dfs(word, start+1, abbr+1, path, res); // abbreviate this char

        if (abbr) path += to_string(abbr);
        dfs(word, start+1, 0, path + word[start], res); // don't abbreviate this char
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

