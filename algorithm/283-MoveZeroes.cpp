#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : swap
class Solution_1 {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] != 0) swap(nums[j], nums[i++]);
            ++j;
        }
    }
};


// Solution 2 : put and set
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] != 0) nums[i++] = nums[j];
        }
        while (i < n) nums[i++] = 0;
    }
};



int main() {
    Solution s;
    return 0;
}
