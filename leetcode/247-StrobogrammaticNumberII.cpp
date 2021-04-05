#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char,char> m = {{'0','0'}, {'1','1'}, {'6','9'}, {'9','6'}, {'8','8'}};
    vector<string> res;

    vector<string> findStrobogrammatic(int n) {
        string path(n, '0');
        dfs(0, n-1, path);
        return res;
    }

    void dfs(int i, int j, string& path) {
        if (i > j) {
            res.push_back(path);
            return;
        }
        for (const auto& p : m) {
            if (i < j && i == 0 && p.first == '0') continue;
            if (i == j && (p.first == '6' || p.first == '9')) continue;
            path[i] = p.first;
            path[j] = p.second;
            dfs(i+1, j-1, path);
        }
    }
};


int main() {
    return 0;
}
