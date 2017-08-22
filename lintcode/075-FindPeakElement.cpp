#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeak(vector<int> nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mid > 0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if (mid > 0 && nums[mid] > nums[mid-1]) left = mid+1;
            else right = mid;
        }
        return 0;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {1, 9, 5, 4, 3, 4, 5, 4};
    cout << s.findPeak(nums) << endl;
    return 0;
}
