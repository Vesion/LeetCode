#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiffSubArrays(vector<int> nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int localMax, localMin;

        vector<int> leftMax(n), leftMin(n);
        localMax = localMin = leftMax[0] = leftMin[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            localMax = max(localMax+nums[i], nums[i]);
            localMin = min(localMin+nums[i], nums[i]);
            leftMax[i] = max(leftMax[i-1], localMax);
            leftMin[i] = min(leftMin[i-1], localMin);
        }
        
        vector<int> rightMax(n), rightMin(n);
        rightMax[n-1] = rightMin[n-1] = localMax = localMin = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            localMax = max(localMax+nums[i], nums[i]);
            localMin = min(localMin+nums[i], nums[i]);
            rightMax[i] = max(rightMax[i+1], localMax);
            rightMin[i] = min(rightMin[i+1], localMin);
        }

        int result = 0;
        for (int i = 0; i < n-1; ++i) {
            result = max(result, max(abs(leftMax[i]-rightMin[i+1]), abs(rightMax[i+1]-leftMin[i])));
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
