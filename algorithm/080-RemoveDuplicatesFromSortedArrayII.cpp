#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int r = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[r-2])
                nums[r++] = nums[i];
        }
        nums.erase(nums.begin()+r, nums.end());
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}

