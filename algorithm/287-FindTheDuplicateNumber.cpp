#include <iostream>
#include <vector>
using namespace std;


// Solution 1 : countign sort, O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        }
        for (int i = 0; i < n; ++i) if (i+1 != nums[i]) return nums[i];
        return n;
    }
};



// Solution 2 : slow-and-fast pointer, like 142-LinkedListCycleII, O(n) time
// It is not easy to think of this idea. Let's consider the array as single list, the number itself is like node's val, nums[number] is like node's next pointer, e.g.
//      [1, 2, 3, 4, 2, 5]    ==>    '1' -> '2' -> '3' -> '4'
//       0  1  2  3  4  5                    ^             |
//                                           |_____________| cycle
// The rest of the work is finding out the entry point of cycle, it has been solved in 142
class Solution_2 {
public:
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
};


int main() {
    return 0;
}
