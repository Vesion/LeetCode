#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(0, nums, res, path);
        return res;
    }

    void dfs(int cur, vector<int>& nums, vector<vector<int>>& res, vector<int>& path) {
        res.push_back(path);
        for (int i = cur; i < (int)nums.size(); ++i) {
            if (i > cur && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(i+1, nums, res, path);
            path.pop_back();
        }
    }
};


int main() {
    return 0;
}
