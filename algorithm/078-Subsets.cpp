#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, nums, path, res);
        return res;
    }

    void dfs(int cur, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        if (cur == (int)nums.size()) {
            res.push_back(path);
            return;
        }
        dfs(cur+1, nums, path, res);
        path.push_back(nums[cur]);
        dfs(cur+1, nums, path, res);
        
    }
};

int main() {
    Solution s;
    return 0;
}

