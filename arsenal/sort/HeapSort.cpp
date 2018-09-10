#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// STL provides several tool functions for heap manipulation: make_heap(), push_heap(), pop_heap(), sort_heap()

// Find i's parent and its children
// Note our index starts from 0, so do not forget the 1 offset
#define parent(i) ((i-1)/2)
#define left(i) (i*2+1)
#define right(i) (i*2+2)

// called after decreasing key i, O(logn)
void shift_down(vector<int>& nums, int n, int i) {
    int max_i = i;
    if (left(i) < n && nums[max_i] < nums[left(i)]) max_i = left(i);
    if (right(i) < n && nums[max_i] < nums[right(i)]) max_i = right(i);
    if (max_i == i) return;
    swap(nums[i], nums[max_i]);
    shift_down(nums, n, max_i);
}

// called after increasing key i, O(logn)
void sift_up(vector<int>& nums, int i) {
    int min_i = i;
    if (i > 0 && nums[i] > nums[parent(i)]) min_i = parent(i);
    if (min_i == i) return;
    swap(nums[i], nums[min_i]);
    sift_up(nums, i);
}

// Shift down from the first 'internal' node (n/2-1), to assure the average O(n) time
void build_heap(vector<int>& nums, int n) {
    for (int i = n/2-1; i >= 0; --i)
        shift_down(nums, n, i);
}

// Swap root with the last node, then re-heapify with new range, O(logn)
void extract_top(vector<int>& nums, int n) {
    swap(nums[0], nums[n-1]);
    shift_down(nums, n-1, 0);
}

// sort, O(nlogn)
void heapSort(vector<int>& nums) {
    int n = nums.size();
    build_heap(nums, n);
    for (int i = 0; i < n; ++i)
        extract_top(nums, n-i);
}

int main() {
    vector<int> nums = {2,7,26,25,19,17,1,90,3,36}; 
    heapSort(nums);
    for (auto i : nums) cout << i << " "; cout << endl;
    return 0;
}
