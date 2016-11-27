#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0 || n == 0) return {};
        vector<vector<int>> res;
        vector<int> path;
        dfs(k, 1, n, path, res);
        return res;
    }

    void dfs(int k, int cur, int n, vector<int>& path, vector<vector<int>>& res) {
        if (k == 0) {
            if (n == 0) res.push_back(path);
            return;
        }
        for (int i = cur; i <= 9; ++i) {
            if (n-i >= 0) {
                path.push_back(i);
                dfs(k-1, i+1, n-i, path, res);
                path.pop_back();
            }
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

