#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : merge sort
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size());
    }
    
    int mergeSort(vector<int>& nums, int first, int last) {
        if (first+1 >= last) return 0;
        int mid = first + (last-first)/2;
        int res = mergeSort(nums, first, mid) + mergeSort(nums, mid, last);
        vector<int> cache(last-first, 0);
        int j = mid, k = mid;
        int r = 0;
        for (int i = first; i < mid; ++i) {
            while (j < last && (long long)nums[i] > (long long)nums[j]*2) ++j;
            res += j-mid;
            while (k < last && nums[k] < nums[i]) cache[r++] = nums[k++];
            cache[r++] = nums[i];
        }
        move(cache.begin(), cache.begin()+r, nums.begin()+first);
        return res;
    }
};


int main() {
    return 0;
}
