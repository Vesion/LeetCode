#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxTwoSubArrays(vector<int> nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        int local;

        local = leftMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            local = max(local+nums[i], nums[i]);
            leftMax[i] = max(leftMax[i-1], local);
        }

        local = rightMax[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            local = max(local+nums[i], nums[i]);
            rightMax[i] = max(rightMax[i+1], local);
        }

        int result = INT_MIN;
        for (int i = 0; i < n-1; ++i) {
            result = max(result, leftMax[i]+rightMax[i+1]);
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
