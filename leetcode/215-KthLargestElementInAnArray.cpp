#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// The classic 'Kth Largest Number' problem

// Solution 1 : quickSelect, O(n^2) best, O(n) worst
//              if we preprocess nums with shuffling it, the O(n) is guaranteed
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


// Solution 2 : max-heap, O(nlogk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};


int main() {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 2) << endl;
    return 0;
}

