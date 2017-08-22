#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid; //     left ... target ... mid ... pivot ...................... right
                else left = mid+1;
            }
            else {
                if (nums[mid] < target && target <= nums[right-1]) left = mid+1; // left ...................... pivot ... mid ... target ... right
                else right = mid;
            }
        }
        return -1;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 1, 2, 3};
    cout << s.search(nums, 4);
    return 0;
}
