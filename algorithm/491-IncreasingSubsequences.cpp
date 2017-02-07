#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 0 : hash whole vector to remove duplicates
// trivial and slow, and we have to use set because unordered_set doesn't provide default hash function for vector


// Solution 1 : use hash table in one level to avoid duplicates
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() > 1) res.push_back(path);
        unordered_set<int> m; // use to avoid duplicates, a number can only occur once in each level
        for (int i = start; i < (int)nums.size(); ++i) {
            // if nums is sorted, we can use the condition below to avoid duplicates
            //      if (i > start && nums[i] == nums[i-1]) continue;
            // but nums is not sorted, so we have to use hash table to remember numbers we have used in this level, as below
            if (m.count(nums[i])) continue;

            if (path.empty() || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                dfs(nums, i+1, path, res);
                path.pop_back();
                m.insert(nums[i]);
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,1,1,1,1,1};
    auto r = s.findSubsequences(nums);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
