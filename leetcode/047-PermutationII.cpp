#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 :use next_permutation in 031-NextPermutation or STL
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};


// Solution 2 : backtracking, generate
// note the difference from 046
class Solution_2 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end()); // sort
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
            if (used[i]) continue;

            // here we can avoid duplicates in two ways
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            //if (i > 0 && nums[i] == nums[i-1] && used[i-1]) continue;
            //
            // the first one: the indexes of duplicates are increasing
            // the second one: the indexes of duplicates are decreasing

            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used, path, res);
            used[i] = false;
            path.pop_back();
        }
    }
};


int main() {
    vector<int> nums = {1,1,2};
    Solution_2 s2;
    auto r = s2.permuteUnique(nums);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
