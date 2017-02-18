#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : use next_permutation in 031-NextPermutation or STL
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};


// Solution 2 : backtracking, generate
class Solution_2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<bool> used(n, false);
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, used, path, res);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used, path, res);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};


// Solution 3 : backtracking, swap
class Solution_3 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == (int)nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); ++i) {
            swap(nums[start], nums[i]);
            dfs(nums, start+1, res);
            swap(nums[start], nums[i]);
        }
    }
};


int main() {
    return 0;
}
