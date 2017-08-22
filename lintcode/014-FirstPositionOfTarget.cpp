#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return nums[left] == target ? left : -1;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {3,4,5,8,8,8,8,10,13,14};
    cout << s.binarySearch(nums, 8) << endl;
    return 0;
}
