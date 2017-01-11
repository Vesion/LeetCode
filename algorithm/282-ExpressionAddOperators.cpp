#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        vector<string> res;
        dfs(num, 0, 0, 0, target, "", res);
        return res;
    }

    void dfs(string& num, int start, long long cur, long long pre, int target, string path, vector<string>& res) {
        if (start == (int)num.size()) {
            if (cur == target) res.push_back(path);
            return;
        }
        for (int i = start; i < (int)num.size(); ++i) {
            if (num[start] == '0' && i > start) return; // if prefix 0s
            string s = num.substr(start, i-start+1);
            long long t = stol(s);
            if (start == 0) 
                dfs(num, i+1, t, t, target, path+s, res);
            else {
                dfs(num, i+1, cur+t, t, target, path+"+"+s, res);
                dfs(num, i+1, cur-t, -t, target, path+"-"+s, res);
                dfs(num, i+1, cur-pre+pre*t, pre*t, target, path+"*"+s, res); // '*' has higher precedence, so we need to recover old pre before multi
            }
        }
    }
};


int main() {
    return 0;
}
