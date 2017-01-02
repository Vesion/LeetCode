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
    vector<bool> used;
    int n;

    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum%4) return false;
        n = nums.size();
        used.resize(n, false);
        return dfs(nums, 0, 0, sum/4, 0);
    }

    bool dfs(vector<int>& nums, int start, int sum, int target, int edges) {
        if (edges == 4) return true;
        if (sum == target) return dfs(nums, 0, 0, target, edges+1);
        if (sum > target) return false;
        for (int i = start; i < n; ++i) {
            if (!used[i]) {
                used[i] = true;
                if (dfs(nums, i+1, sum+nums[i], target, edges)) return true;
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
