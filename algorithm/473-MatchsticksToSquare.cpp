#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// This is a 'set partition' problem, it's NPC.

// Solution 1 : backtracking
// contruct edges one by one
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum%4) return false;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        return dfs(nums, 0, 0, sum/4, 0, used);
    }

    bool dfs(vector<int>& nums, int start, int sum, int target, int edges, vector<bool>& used) {
        if (edges == 3) return true; // we only need to construct 3 edges
        if (sum == target) return dfs(nums, 0, 0, target, edges+1, used); // one edge complete
        for (int i = start; i < (int)nums.size(); ++i) {
            if (used[i]) continue;
            if (sum+nums[i] > target) return false;
            used[i] = true;
            if (dfs(nums, i+1, sum+nums[i], target, edges, used)) return true;
            used[i] = false;
        }
        return false;
    }
};


// Solution 2 : backtracking, for each number
// we can put it into 4 different sets
class Solution_2 {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum%4) return false;
        sort(nums.begin(), nums.end(), greater<int>()); // sort nums in descending order to make dfs run much faster
        vector<int> sums(4, 0);
        return dfs(nums, 0, sums, sum/4);
    }

    bool dfs(vector<int>& nums, int start, vector<int>& sums, int target) {
        if (start == (int)nums.size()) {
            return (sums[0] == target && sums[1] == target && sums[2] == target);
        }
        for (int i = 0; i < 4; ++i) {
            if (sums[i]+nums[start] > target) continue;
            sums[i] += nums[start];
            if (dfs(nums, start+1, sums, target)) return true;
            sums[i] -= nums[start];
        }
        return false;
    }
};


int main() {
    return 0;
}
