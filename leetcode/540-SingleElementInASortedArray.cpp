#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : binary search, O(logn), verbose
class Solution_1 {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n-1;
    while (left <= right) {
      int mid = left + (right-left)/2;
      if ((mid == 0 && nums[mid] != nums[mid+1]) || (mid == n-1 && nums[mid] != nums[mid-1]) || (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])) return nums[mid];
      if (mid == 0 || nums[mid] == nums[mid-1]) {
        if ((mid-left+1) & 1) right = mid-2;
        else left = mid+1;
      } else {
        if ((right-mid+1) & 1) left = mid+2;
        else right = mid-1;
      }
    }
    return nums[left];
  } 
};


// Solution 2 : binary search, O(logn), elegant
// we want to find the first even-index number not followed by the same number
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size()/2;
    while (left < right) {
      int mid = left + (right-left)/2;
      if (nums[2*mid] != nums[2*mid+1]) right = mid;
      else left = mid+1;
    }
    return nums[2*left];
  } 
};


int main() {
  Solution s;
  vector<int> nums = {1,1,2,3,3,4,4,8,8};
  cout << s.singleNonDuplicate(nums) << endl;
  return 0;
}
