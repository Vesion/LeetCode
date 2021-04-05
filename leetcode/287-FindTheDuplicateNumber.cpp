#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : binary search, O(nlogn)
class Solution_1 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int c = 0;
            for (int& num : nums) if (num <= mid) ++c;
            if (c > mid) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};


// Solution 2.1 : sort, O(nlogn)
class Solution2_1 {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; ++i) if (nums[i] == nums[i-1]) return nums[i];
        return n;
    }
};

// Solution 2 : countign sort, O(n), but have to modify the array
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


// Solution 3 : slow-and-fast pointer, like 142-LinkedListCycleII, O(n) time, O(1) space
// It is not easy to think of this idea. Let's consider the array as single list,
// the number itself is like node's val, nums[number] is like node's next pointer, e.g.
//      [1, 2, 3, 4, 2, 5]    ==>    '1' -> '2' -> '3' -> '4'
//       0  1  2  3  4  5                    ^             |
//                                           |_____________| cycle
// The rest of the work is finding out the entry point of cycle, it has been solved in 142
class Solution3 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        fast = nums[0];
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
