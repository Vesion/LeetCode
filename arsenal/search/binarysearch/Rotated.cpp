#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Four most important things in binary search:
// 1. initial range
//      recommend to use inclusive range [left, right] 
//
// 2. terminating condition
//      while (left <= right) or while (left < right)
//
// 3. how to shrink range
//      first get mid, then choose left or right half according to target's position
//
// 4. what to return
//      return left or right according to which one is finally valid


// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution_search_in_rotated {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) right = mid-1;
                else left = mid+1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};


// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution_find_min_in_rotated {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = left + (right-left)/2;
            if (nums[mid] >= nums[left]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }
};


int main() {
    return 0;
}
