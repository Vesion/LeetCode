#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// generate path, abbreviate current character or not
// similar to generate all subsets
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(word, 0, "", 0, res);
        return res;
    }

    void dfs(string word, int start, string path, int abbrs, vector<string>& res) {
        if (start == (int)word.size()) {
            if (abbrs > 0) path += to_string(abbrs);
            res.push_back(path);
            return;
        }
        dfs(word, start+1, path, abbrs+1, res); // abbreviate this characher

        if (abbrs) path += to_string(abbrs); // don't abbreviate this character
        dfs(word, start+1, path + word[start], 0, res);
    }
};

int main() {
    Solution s;
    auto r = s.generateAbbreviations("word");
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

