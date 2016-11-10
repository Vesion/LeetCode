#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int i = n-2;
        while (i >= 0 && nums[i] >= nums[i+1]) --i; // from right to left, find the first one smaller than its right neighbour
        if (i == -1) { // if not found, it's the last permutation, reverse and return
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size()-1;
        while (j > i && nums[j] <= nums[i]) --j; // from right to left, find the first one larger than i
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
    }
};

int main() {
    Solution s;
    return 0;
}

