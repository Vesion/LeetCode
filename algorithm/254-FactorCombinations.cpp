#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : with prune, 0ms
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if (n <= 2) return {};
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, 2, path, res);
        return res;
    }
    
    void dfs(int n, int start, vector<int>& path, vector<vector<int>>& res) {
        for (int i = start; i <= n/i; ++i) {
            if (n % i == 0) {
                path.push_back(i);
                dfs(n/i, i, path, res);
                path.pop_back();
            }
        }
        if (!path.empty()) {
            path.push_back(n);
            res.push_back(path);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    auto r = s.getFactors(32);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }

    return 0;
}
