#include <iostream>
#include <vector>
using namespace std;

// similiar to 081-SearchInRotatedSortedArrayII
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while (left < right) {
        if (nums[left] < nums[right]) // no ratation in the array, return the first element directly
            return nums[left];
        int mid = left + (right-left)/2;
        if (nums[mid] > nums[left]) // rotation is in the second half
            left = mid + 1;
        else if (nums[mid] < nums[left]) // rotation is in the first half
            right = mid;
        else // if nums[mid] == nums[left], try to ++left for next decision
            ++left;
    }
    return nums[left];
}

int main() {
    //vector<int> nums = {3, 5, 6, 7, 8, 0, 1, 2};
    vector<int> nums = {3, 3, 5, 5, 6, 7, 3, 3};
    cout << findMin(nums) << endl;
    return 0;
}

