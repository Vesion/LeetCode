#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) 
                return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            } else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> n = {1};
    cout << s.search(n, 0);
    return 0;
}

