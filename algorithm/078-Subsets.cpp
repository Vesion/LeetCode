#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dfs
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, nums, res, path);
        return res;
    }

    void dfs(int cur, vector<int>& nums, vector<vector<int>>& res, vector<int>& path) {
        res.push_back(path);
        for (int i = cur; i < (int)nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(i+1, nums, res, path);
            path.pop_back();
        }
    }
};


// Solution 2 : bit manipulation
class Solution_2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1<<n); ++i) {
            vector<int> path;
            for (int j = 0; j < n; ++j) {
                if ((i>>j) & 1) path.push_back(nums[j]);
            }
            res.push_back(path);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

