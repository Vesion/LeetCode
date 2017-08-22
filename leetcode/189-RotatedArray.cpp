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
class Solution_2 {
public:
    void rotate(vector<int>& nums, int k) {
        int *a = &nums[0];
        int n = nums.size();
        for (; k %= n; n -= k, a += k) {
            // Swap the last k elements with the first k elements. 
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements to the right by k steps.
            for (int i = 0; i < k; i++)
                swap(a[i], a[n-k+i]);
        }
    }
};


int main() {
    Solution s;
    return 0;
}

