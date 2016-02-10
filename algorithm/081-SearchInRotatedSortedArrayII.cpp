#include <iostream>
#include <vector>
using namespace std;

// similiar to No.033
bool search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int first = 0, last = nums.size();

    while (first < last) {
        int mid = first + (last - first) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[first] < nums[mid]) { // cannot be <= any more
            if (nums[first] <= target && target < nums[mid])
                last = mid;
            else
                first = mid + 1;
        }
        else if (nums[first] > nums[mid]) {
            if (nums[mid] < target && target <= nums[last-1])
                first = mid + 1;
            else
                last = mid;
        }
        else { // if nums[first] == nums[mid], try to ++first for more decision
            ++first;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 3, 1, 1};
    cout << search(nums, 3);
    return 0;
}
