#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : calculate left-product and right-product respectively, two passes
// In order to solve in-place, we use a temporary product, instead of vector
class Solution_1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();
        vector<int> res(n, 1);
        int tmp = 1;
        for (int i = 0; i < n; ++i) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        tmp = 1;
        for (int i = n-1; i >= 0; --i) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        return res;
    }
};


// Solution 2 : one pass, O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = 1;
        vector<int> res(n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] *= left;
            left *= nums[i];
            res[n-i-1] *= right;
            right *= nums[n-i-1];
        }
        return res;
    }
};


int main() {
    return 0;
}
