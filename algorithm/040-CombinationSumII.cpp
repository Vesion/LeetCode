#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, res, path);
        return res;
    }

    void dfs(vector<int>& candidates, int remain, int start, vector<vector<int>>& res, vector<int>& path) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        int pre = -1;
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (candidates[i] > remain) return;
            if (candidates[i] == pre) continue;
            path.push_back(candidates[i]);
            dfs(candidates, remain-candidates[i], i+1, res, path);
            path.pop_back();
            pre = candidates[i];
        }
    }
};

int main() {
    Solution s;
    return 0;
}
