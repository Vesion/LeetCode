#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, 0, 0, target, 0, "", res);
        return res;
    }
    
    void dfs(string& s, int start, long long sum, long long target, long long pre, string path, vector<string>& res) {
        if (start == (int)s.size()) {
            if (sum == target) res.push_back(path);
            return;
        }
        for (int i = start; i < (int)s.size(); ++i) {
            if (i > start && s[start] == '0') return; // prefix '0' is invalid
            string num = s.substr(start, i-start+1);
            long long t = stol(num);
            if (start == 0) dfs(s, i+1, t, target, t, path+num, res);
            else {
                dfs(s, i+1, sum+t, target, t, path+"+"+num, res);
                dfs(s, i+1, sum-t, target, -t, path+"-"+num, res);
                dfs(s, i+1, sum-pre+pre*t, target, pre*t, path+"*"+num, res);
            }
        }
    }
};


int main() {
    return 0;
}
