#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, n, k, path, res);
        return res;
    }

    void dfs(int cur, int n, int k, vector<int>& path, vector<vector<int>>& res) {
        if ((int)path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i <= n; ++i) {
            path.push_back(i);
            dfs(i+1, n, k, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    return 0;
}

