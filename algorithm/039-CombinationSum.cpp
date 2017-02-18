#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        dfs(candidates, 0, target, path, res);
        return res;
    }
    
    void dfs(vector<int>& candidates, int start, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (target-candidates[i] < 0) return;
            path.push_back(candidates[i]);
            dfs(candidates, i, target-candidates[i], path, res); // each number can be used unlimited times
            path.pop_back();
        }
    }
};


int main() {
    return 0;
}
