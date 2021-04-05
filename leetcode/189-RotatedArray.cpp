#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : reverse, O(n) time, O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};


// Solution 2 : swap, O(n) time, O(1) space
// swap first k numbers with last k numbers, then degrade problem from a[0...n] to a[k...n]
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; k %= n; n -= k, i += k) {
            for (int j = 0; j < k; ++j) {
                swap(nums[i+j], nums[i+n-k+j]);
            }
        }
    }
};


int main() {
    Solution s;
    return 0;
}

