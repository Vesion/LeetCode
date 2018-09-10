#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/
//
// Problem: Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

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
  return 0;
}
