#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            if (nums[j] != 0) swap(nums[i++], nums[j]);
            ++j;
        }
    }
};


int main() {
    return 0;
}
