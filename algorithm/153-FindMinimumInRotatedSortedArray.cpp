#include <iostream>
#include <vector>
using namespace std;

// similiar to 033-SearchInRotatedSortedArray
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while (left < right) {
        if (nums[left] < nums[right]) // no ratation in the array, return the first element directly
            return nums[left];
        int mid = left + (right-left)/2;
        if (nums[mid] >= nums[left]) // rotation is in the second half
            left = mid + 1;
        else // rotation is in the first half
            right = mid;
    }
    return nums[left];
}

int main() {
    //vector<int> nums = {3, 5, 6, 7, 8, 0, 1, 2};
    vector<int> nums = {2, 3 ,1};
    cout << findMin(nums) << endl;
    return 0;
}
