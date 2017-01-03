#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dfs, generate path
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        if (start == (int)nums.size()) {
            res.push_back(path);
            return;
        }
        dfs(nums, start+1, path, res);
        path.push_back(nums[start]);
        dfs(nums, start+1, path, res);
        path.pop_back();
    }
};


// Solution 2 : bitmap, there are total 2^n subsets
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
    return 0;
}

