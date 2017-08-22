#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, 0, 0, 0, target, "", res);
        return res;
    }
    
    void dfs(string& s, int start, long long sum, long long pre, int target, string path, vector<string>& res) {
        if (start == (int)s.size()) {
            if (sum == target) res.push_back(path);
            return;
        }
        for (int i = start; i < (int)s.size(); ++i) {
            if (i > start && s[start] == '0') return; // prefix '0' is invalid
            string t = s.substr(start, i-start+1);
            long long num = stol(t);
            if (start == 0) dfs(s, i+1, num, num, target, path+t, res);
            else { 
                dfs(s, i+1, sum+num, num, target, path+"+"+t, res);
                dfs(s, i+1, sum-num, -num, target, path+"-"+t, res);
                dfs(s, i+1, sum-pre+pre*num, pre*num, target, path+"*"+t, res);
            }
        }
    }
};


int main() {
    return 0;
}
