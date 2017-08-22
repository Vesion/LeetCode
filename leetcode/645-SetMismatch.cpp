#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; ++i) {
          while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
      }
      vector<int> res;
      for (int i = 0; i < n; ++i) {
          if (nums[i] != i+1) res = {nums[i], i+1};
      }
      return res;
  }
};


int main() {
  return 0;
}
