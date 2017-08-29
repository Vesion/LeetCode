#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size(), c = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i-1]) {
        if (i == 1 || nums[i] >= nums[i-2]) nums[i-1] = nums[i];
        else nums[i] = nums[i-1];
        ++c;
      }
    }
    return c <= 1;
  }
};


int main() {
  Solution s;
  vector<int> nums = {4, 2, 1};
  cout << s.checkPossibility(nums) << endl;
  return 0;
}
