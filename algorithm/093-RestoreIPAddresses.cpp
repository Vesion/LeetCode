#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return {};
        vector<string> res;
        vector<string> path;
        dfs(s, 0, "", 0, res);
        return res;
    }

    void dfs(string& s, int cur, string path, int points, vector<string>& res) {
        if (points > 4 || cur > (int)s.size()) return;
        if (points == 4 && cur == (int)s.size()) {
            res.push_back(path);
            return;
        }
        for (int l = 1; l <= 3; ++l) {
            if (cur+l > (int)s.size()) break;
            string sub = s.substr(cur, l);
            if ((sub.size() > 1 && sub[0] == '0') || (stoi(sub) > 255)) continue;
            dfs(s, cur+l, path + sub + (points == 3 ? "" : "."), points+1, res);
        }
    }
};

int main() {
    Solution s;
    auto r = s.restoreIpAddresses("1111");
    for (auto& e : r) cout << e << endl; cout << endl; 
    return 0;
}

