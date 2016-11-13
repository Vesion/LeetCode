#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, 0, target, path, res);
        return res;
    }

    void dfs(vector<int>& candidates, int cur, int remain, vector<int>& path, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < (int)candidates.size(); ++i) {
            if (candidates[i] > remain) return;
            path.push_back(candidates[i]);
            dfs(candidates, i, remain-candidates[i], path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> a = {2,3,6,7};
    auto r = s.combinationSum(a, 7);;
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

