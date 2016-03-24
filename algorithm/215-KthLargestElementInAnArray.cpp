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

// Solution 1 : use std::nth_element (similiar to above, but here only partial sort)
int findKthLargest_stl(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
    return nums[k-1];
}

// Solution 2 : use the 'partition' step in quicksort, O(n*lgk)
// actually do not sort first k elements
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
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
}


// Solution 3 : use max-heap, partial heap sort, heap-building O(n), get first k elements O(klgn), so totally O(n) if k is not very large
// here we use std::priority_queue directly
int findKthLargest_heap(vector<int>& nums, int k) {
    priority_queue<int> q;
    for (auto & n : nums) q.push(n);
    while (--k) q.pop();
    return q.top();
}


int main() {
    vector<int> nums = {4, 5, 1, 2, 6, 3, 7, 9, 8};
    cout << findKthLargest_bf(nums, 2) << endl;
    cout << findKthLargest_stl(nums, 2) << endl;
    cout << findKthLargest_partition(nums, 2) << endl;
    cout << findKthLargest_heap(nums, 2) << endl;
    return 0;
}
