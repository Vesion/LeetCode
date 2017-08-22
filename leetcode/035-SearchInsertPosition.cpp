#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// lower_bound
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    Solution s;
    return 0;
}

