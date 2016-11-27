#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// The classic 'Kth Largest Number' problem

// Solution 1 : partition, O(n) average
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size();
        while (left < right) {
            int p = partion(nums, left, right);
            if (p+1 == k) return nums[p];
            if (p+1 < k) left = p+1;
            else right = p;
        }
        return 0;
    }

    int partion(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left+1, j = right-1;
        while (i <= j) {
            while (i <= j && nums[i] >= pivot) ++i;
            while (i <= j && nums[j] <= pivot) --j;
            if (i <= j) swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        return j;
    }
};


// Solution 2 : max-heap, O(klogn)
class Solution_2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        while (--k) q.pop();
        return q.top();
    }
};


int main() {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 2) << endl;
    return 0;
}

