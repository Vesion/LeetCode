#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[left] < nums[right]) return nums[left];
            if (nums[mid] >= nums[left]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }

    //int findMin(vector<int> &nums) {
        //if (nums.empty()) return 0;
        //int left = 0, right = nums.size();
        //while (left < right) {
            //int mid = left + (right-left)/2;
            //if (mid == 0 || nums[mid] < nums[mid-1]) return nums[mid];
            //if (nums[left] > nums[right-1] && nums[mid] > nums[left]) left = mid+1;
            //else right = mid;
        //}
        //return nums[left];
    //}

};

int main() {
    Solution s;
    //vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {1};
    cout << s.findMin(nums) << endl;
    return 0;
}
