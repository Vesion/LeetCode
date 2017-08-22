#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Binary search result
class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double left = INT_MAX, right = INT_MIN;
    for (int& num : nums) {
      left = min(left, (double)num);
      right = max(right, (double)num);
    }

    while (left+1e-5 < right) {
      double mid = left + (right-left)/2;
      if (valid(nums, mid, k)) left = mid;
      else right = mid;
    }
    return right;
  }

  // check if we can find a subarray whose average is larger than or equal to avg
  bool valid(vector<int>& nums, double avg, int k) {
    double sum = 0, pre_sum = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      sum += nums[i]-avg;
      if (i >= k) pre_sum += nums[i-k]-avg;
      if (pre_sum < 0) {
        sum -= pre_sum;
        pre_sum = 0;
      }
      if (i >= k-1 && sum >= 0) return true;
    }
    return false;
  }
};


int main() {
  Solution s;
  vector<int> nums = {1,12,-5,-6,50,3};
  cout << s.findMaxAverage(nums, 4) << endl;
  return 0;
}
