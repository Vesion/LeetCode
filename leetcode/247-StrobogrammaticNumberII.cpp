#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char,char> m = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        vector<string> res;
        string path(n, '0');
        dfs(0, n-1, m, path, res);
        return res;
    }
    
    void dfs(int start, int end, unordered_map<char,char>& m, string& path, vector<string>& res) {
        if (start > end) {
            res.push_back(path);
            return;
        }
        for (auto& p : m) {
            if (start < end && start == 0 && p.first == '0') continue; // prefix '0' is invalid
            if (start == end && (p.first == '6' || p.first == '9')) continue; // the exact middle one cannot be '6' or '9'
            path[start] = p.first;
            path[end] = p.second;
            dfs(start+1, end-1, m, path, res);
        }
    }
};


int main() {
    return 0;
}
