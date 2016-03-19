#include <iostream>
#include <vector>
using namespace std;

// the famous 'Duplicate Number' problem
// Put n+1 numbers between [1, n+1] in n slots, according to the 'Pigeon Hole Principle', there must be at least one duplicate number.


// Solution 0 : sort and binary search, O(nlgn + lgn) time
// does not meet requirement of question, because we need to either modify the nums or use extra space
int findDuplicate_sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right-left)/2;
        if (mid < nums[mid]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}


// Solution 1 : slow-and-fast pointer, like 142-LinkedListCycleII, O(n) time
// It is not easy to think of this idea. Let's consider the array as single list, the number itself is like node's val, nums[number] is like node's next pointer, e.g.
//      [1, 2, 3, 4, 2, 5]    ==>    '1' -> '2' -> '3' -> '4'
//       0  1  2  3  4  5                    ^             |
//                                           |_____________| cycle
// The rest of the work is finding out the entry point of cycle, it has been solved in 142
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[nums[0]]; // slow and fast pointer
    while (slow != fast) {
        slow = nums[slow]; // slow goes one step
        fast = nums[nums[fast]]; // fast goes two steps
    }
    // they meet in cycle, nextly, they go from beginning and meet point with same speed
    fast = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}


int main() {
    vector<int> nums = {1, 3, 4, 2, 2}; // 6 numbers in 5 slots
    cout << findDuplicate(nums) << endl;
    return 0;
}
