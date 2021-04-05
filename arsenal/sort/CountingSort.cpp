#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Common counting sort use O(n) time and O(n) space to sort, see CLRS.

// Here is a special situation:
//      Given an array of size N, all numbers in the array are in the range [1, N]
//
// Solution:
//      The main idea is put number to its right place.
//      Go through the array sequentially and for every index
//      write the value at the index to the index specified by value.
//
// In this situation, we can sort in-place and in average O(n) time.
// This can solve many problems such as 'Find missing number' or 'Find  duplicates'...

// e.g.
//
// https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
            swap(nums[nums[i]-1], nums[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i+1) return i+1;
    }
    return n+1;
}


// https://leetcode.com/problems/missing-number
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] < n && nums[i] != nums[nums[i]])
            swap(nums[nums[i]], nums[i]);
    }
    for (int i = 0; i < n; ++i)
        if (i != nums[i]) return i;
    return n;
}


// https://leetcode.com/problems/find-the-duplicate-number/
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
    }
    for (int i = 0; i < n; ++i) if (i+1 != nums[i]) return nums[i];
    return n;
}


// https://leetcode.com/problems/find-all-duplicates-in-an-array
vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i+1) res.push_back(nums[i]);
    }
    return res;
}


// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i+1) res.push_back(i+1);
    }
    return res;
}


int main() {
    return 0;
}
