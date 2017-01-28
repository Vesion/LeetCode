#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size();
        int i = 0, i0 = 0, i2 = n-1;
        while (i <= i2) {
            if (nums[i] == 0) swap(nums[i0++], nums[i++]);
            else if (nums[i] == 2) swap(nums[i2--], nums[i]); // keep i staying here, in case of 0 comes from back end
            else ++i;
        }
    }
};


int main() {
    return 0;
}

