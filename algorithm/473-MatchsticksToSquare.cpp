#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// This is a 'set partition' problem, it's NPC.
// backtracking, O(2^n)
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum%4) return false;
        vector<bool> used(nums.size(), false);
        return dfs(nums, 0, 0, sum/4, 0, used);
    }

    bool dfs(vector<int>& nums, int start, int sum, int target, int edges, vector<bool>& used) {
        if (edges == 3) return true; // we only need to construct 3 edges
        if (sum == target) return dfs(nums, 0, 0, target, edges+1, used); // one edge complete
        for (int i = start; i < (int)nums.size(); ++i) {
            if (!used[i] && sum+nums[i] <= target) {
                used[i] = true;
                if (dfs(nums, i+1, sum+nums[i], target, edges, used)) return true;
                used[i] = false;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = {};
    cout << s.makesquare(nums) <<endl;
    return 0;
}
