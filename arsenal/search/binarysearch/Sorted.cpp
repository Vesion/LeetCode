#include <iostream>
#include <vector>
using namespace std;


// First of all, below is two kinds of binary search

// 1. search target in nums[left, ..., right], note closed
int binary_search_close(vector<int>&nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (nums[mid] > target) right = mid-1;
        else if (nums[mid] < target) left = mid+1;
        else return mid;
    }
    return -1;
}

// 2. search target in nums[left, ..., right), note open
int binary_search_open(vector<int>&nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right-left)/2;
        if (nums[mid] > target) right = mid;
        else if (nums[mid] < target) left = mid+1;
        else return mid;
    }
    return -1;
}


// Then, below is std binary search

// Returns true if any element in the range [first,last) is equivalent to val, and false otherwise.
// std::binary_search
bool binarySearch(vector<int>& nums, int target) {
    if (nums.empty()) return false;
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return false;
}


// Returns position of the first element which is greater than or equal to (>=) val. If all the element are less than val, the function returns nums.size().
// e.g.  1 2 3 3 3 4 5   lowerBound(nums, 3)
//           ^
// std::lower_bound
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}


// Returns position of the first element which is greater than(>) val. If all the element are less than or equal to val, the function returns nums.size().
// e.g.  1 2 3 3 3 4 5   upperBound(nums, 3)
//                 ^
// std::upper_bound
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}


int main() {
    vector<int> v({1, 2, 3, 3, 6, 7, 9});
    cout << binary_search_close(v, 3) <<endl;
    cout << binary_search_open(v, 3) <<endl;
    cout << binarySearch(v, 3) << endl;
    cout << lowerBound(v, 3) << endl;
    cout << upperBound(v, 3) << endl;
    return 0;
}
