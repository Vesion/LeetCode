#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(dp(nums, 0, n-1), dp(nums, 1, n));
    }

    int dp(vector<int>& nums, int start, int end) {
        int notrob = 0, rob = 0;
        for (int i = start; i < end; ++i) {
            int tmp = notrob;
            notrob = max(notrob, rob);
            rob = tmp + nums[i];
        }
        return max(notrob, rob);
    }
};

int main() {
    Solution s;
    return 0;
}

