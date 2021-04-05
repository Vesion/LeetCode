#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(0, candidates, target, path);
        return res;
    }

    void dfs(int start, const vector<int>& nums, int target, vector<int>& path) {
        if (start == nums.size() || target == 0) {
            if (target == 0) res.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (target-nums[i] < 0) continue;
            path.push_back(nums[i]);
            dfs(i, nums, target-nums[i], path);
            path.pop_back();
        }
    }
};


int main() {
    return 0;
}
