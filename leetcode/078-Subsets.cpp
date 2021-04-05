#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1
// generate a full binary tree
// for each number, we have two choices(pick or not pick), only leaf node is a result
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }

    void dfs(const vector<int>& nums, int start, vector<int>& path) {
        if (start == nums.size()) {
            res.push_back(path);
            return;
        }
        dfs(nums, start+1, path);
        path.push_back(nums[start]);
        dfs(nums, start+1, path);
        path.pop_back();
    }
};


// Solution 2 :
// nary-tree, much shallower than binary tree
// in each dfs call, we want to pick a number for the path, so we try all numbers starting from `start`
class Solution2 {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }

    void dfs(const vector<int>& nums, int start, vector<int>& path) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i+1, path);
            path.pop_back();
        }
    }
};


// Solution 3 : bitmap, there are total 2^n subsets
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1<<n); ++i) {  // the bit pattern that how we choose numbers
            vector<int> path;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) path.push_back(nums[j]);
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

