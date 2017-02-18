#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : backtracking, generate
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
    
    // will generate a perfect binary tree
    // so dfs() will be called 2^(n+1)-1 times
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


// Solution 2 : backtracking, combination
class Solution_2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
    
    // 2^n = 1 + 2^0 + 2^1 + 2^2 + ... + 2^(n-1)
    // dfs() will be called 2^n times
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < (int)nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i+1, path, res);
            path.pop_back();
        }
    }
};


// Solution 3 : bitmap, there are total 2^n subsets
class Solution_3 {
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
    Solution_2 s;
    vector<int> nums = {1,2,3};
    auto r = s.subsets(nums);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

