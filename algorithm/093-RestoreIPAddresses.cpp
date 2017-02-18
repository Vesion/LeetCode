#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }
    
    void dfs(string&s, int start, vector<string>& path, vector<string>& res) {
        if (path.size() == 4) {
            if (start == (int)s.size()) {
                string r = path[0];
                for (int i = 1; i < 4; ++i) r += "." + path[i];
                res.push_back(r);
            }
            return;
        }
        for (int i = start; i < (int)s.size(); ++i) {
            if (i > start && s[start] == '0') return; // prefix 0 is invalid
            string num = s.substr(start, i-start+1);
            if (stoi(num) > 255) return;
            path.push_back(num);
            dfs(s, i+1, path, res);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    auto r = s.restoreIpAddresses("10111");
    for (auto& e : r) cout << e << endl; cout << endl; 
    return 0;
}
