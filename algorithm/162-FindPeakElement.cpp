#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[mid+1]) // if nums[mid] > nums[mid+1], there must be a peak in nums[left,...,mid]
                right = mid;
            else // if nums[mid] < nums[mid+1], there must be a peak in nums[mid+1,...,right]
                left = mid+1;
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}

