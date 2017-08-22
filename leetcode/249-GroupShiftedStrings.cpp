#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;


// convert each string into the 'head string in a sequence'
//      e.g. "ba" -> "az"
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (string& s : strings) {
            int d = s[0]-'a';
            string cs = s;
            for (char& c : cs) c = c-d >= 'a' ? c-d : c-d+26;
            m[cs].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& p : m) res.push_back(p.second);
        return res;
    }
};


int main() {
    Solution s;
    vector<string> ss = { "abc","bcd","acef","xyz","az","ba","a","z" };
    auto r = s.groupStrings(ss);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
