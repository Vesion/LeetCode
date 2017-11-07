#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    for (int& num : nums) sum += num;
    if (sum%k) return false;
    vector<bool> visited(n, false);
    sort(nums.begin(), nums.end());
    return dfs(0, nums, 0, sum/k, k, visited);
  }

  bool dfs(int i, vector<int>&nums, int sum, int target, int k, vector<bool>& visited) {
    if (i == (int)nums.size()) {
      if (sum == target) {
        if (k == 1) return true;
        return dfs(0, nums, 0, target, k-1, visited);
      }
      return false;
    }
    if (dfs(i+1, nums, sum, target, k, visited)) return true;
    if (!visited[i]) {
      if (sum+nums[i] > target) return false;
      visited[i] = true;
      if (dfs(i+1, nums, sum+nums[i], target, k, visited)) return true;
      visited[i] = false;
    }
    return false;
  }
};


int main() {
  Solution s;
  vector<int> nums = { 2,2,2,2,3,4,5 };
  cout << s.canPartitionKSubsets(nums, 4) << endl;
  return 0;
}
