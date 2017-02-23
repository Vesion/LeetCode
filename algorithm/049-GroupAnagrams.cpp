#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string& s : strs) {
            string c = s;
            sort(c.begin(), c.end());
            m[c].push_back(s);
        }
        for (auto& p : m) res.push_back(p.second);
        return res;
    }
};


int main() {
    return 0;
}
