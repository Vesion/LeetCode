#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Sort, O(NlogN)
// Actually do not need sort, only need minimum four and maximum four values.
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int x4 = nums[n-4] - nums[0];
        int x3 = nums[n-3] - nums[1];
        int x2 = nums[n-2] - nums[2];
        int x1 = nums[n-1] - nums[3];
        return min(min(x3, x4), min(x1, x2));
    }
};


// Partial sort, O(NlogK)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        // Get sorted first 4 numbers
        partial_sort(nums.begin(), nums.begin()+4, nums.end());
        // Get sorted last 4 numbers
        nth_element(nums.begin()+4, nums.end()-4, nums.end());
        sort(nums.end()-4, nums.end());

        int x4 = nums[n-4] - nums[0];
        int x3 = nums[n-3] - nums[1];
        int x2 = nums[n-2] - nums[2];
        int x1 = nums[n-1] - nums[3];
        return min(min(x3, x4), min(x1, x2));
    }
};

int main() {

}
