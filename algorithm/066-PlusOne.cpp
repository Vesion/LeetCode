#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        nums.back() += 1;
        int carry = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
            carry += nums[i];
            nums[i] = carry%10;
            carry /= 10;
        }
        if (carry) nums.insert(nums.begin(), carry);
        return nums;
    }
};


int main() {
    return 0;
}

