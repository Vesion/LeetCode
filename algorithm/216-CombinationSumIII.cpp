#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, k, n, path, res);
        return res;
    }
    
    void dfs(int start, int k, int remain, vector<int>& path, vector<vector<int>>& res) {
        if ((int)path.size() == k) {
            if (remain == 0) res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            if (remain-i < 0) return;
            path.push_back(i);
            dfs(i+1, k, remain-i, path, res);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    auto r = s.combinationSum3(3, 9);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

