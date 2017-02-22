#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// no duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = left + (right-left)/2;
            if (nums[mid] >= nums[left]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }
};


int main() {
    return 0;
}
