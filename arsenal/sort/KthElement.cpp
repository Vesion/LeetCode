#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// The quite well-kown 'kth largest element' problem.
// Same with 'Beauty of Programming' problem 2.5


// Solution 0 : brute-force, sort the whole array, O(nlgn) + O(1)
int findKthLargest_bf(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k-1];
}


// Solution 1 : make a min-heap of k elements, then compare top with the rest elements, O(n*lgk)
// here use std::make_heap directly
int findKthLargest_heap(vector<int>& nums, int k) {
    int n = nums.size();
    make_heap(nums.begin(), nums.begin()+k, greater<int>()); // make a min-heap
    for (int i = k; i < n; ++i) {
        if (nums[i] > nums[0]) {
            swap(nums[0], nums[i]);
            make_heap(nums.begin(), nums.begin()+k);
        }
    }
    return nums[0];
}


// Solution 2 : divide and conquer, use partion, O(n) on average (expect)
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left]; // may cause O(n^2), can be resolved by picking 'median of three'
    int l = left+1, r = right;
    while (l <= r) {
        while (l <= r && nums[l] >= pivot) ++l;
        while (l <= r && nums[r] <= pivot) --r;
        if (l <= r)
            swap(nums[l++], nums[r--]);
    }
    swap(nums[left], nums[r]);
    return r;
}

int findKthLargest_partition(vector<int>& nums, int k) {
    int left = 0, right = nums.size()-1;
    while (true) {
        int pos = partition(nums, left, right);
        if (pos == k-1) return nums[pos];
        if (pos > k-1) right = pos - 1;
        else left = pos + 1;
    }
    return 0; // never
}


// Solution 3 : use std::nth_element, O(n) on average (expect)
int findKthLargest_stl(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
    return nums[k-1];
}


int main() {
    vector<int> nums = {4, 5, 1, 2, 6, 3, 7, 9, 8};
    cout << findKthLargest_bf(nums, 2) << endl;
    cout << findKthLargest_stl(nums, 2) << endl;
    cout << findKthLargest_partition(nums, 2) << endl;
    cout << findKthLargest_heap(nums, 2) << endl;
    return 0;
}
