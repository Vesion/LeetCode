#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Given an array nums, find the minimum range [i, j] (i <= j), if we sort nums[i:j], the whole array will be sorted.


// Solution 1 : sort, O(nlogn)
class Solution_1 {
public:
    int minToSortRange(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != sorted[i]) { left = i-1; break; }
        }
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] != sorted[i]) { right = i+1; break; }
        }
        return right-left-1;
    }
};


// Solution 2 : greedy, O(n)
class Solution_2 {
public:
    int minToSortRange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, minv = INT_MAX;
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] > minv) left = i;
            minv = min(minv, nums[i]);
        }
        int right = 0, maxv = INT_MIN; 
        for (int i = 0; i < n; ++i) {
            if (nums[i] < maxv) right = i;
            maxv = max(maxv, nums[i]);
        }
        return right-left+1;
    }
};


int main() {
    vector<int> nums = {1, 4, 3, 2, 5};
    Solution_1 s1;
    cout << s1.minToSortRange(nums) <<endl;
    Solution_2 s2;
    cout << s2.minToSortRange(nums) <<endl;
    return 0;
}
