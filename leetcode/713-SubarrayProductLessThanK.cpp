#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int i = 0, j = 0, p = 1;
    int res = 0;
    while (j < (int)nums.size()) {
      p *= nums[j++];
      while (p >= k && i < j) {
        p /= nums[i++];
      }
      res += j-i;
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  cout << s.numSubarrayProductLessThanK(nums, 0) << endl;
  return 0;
}
