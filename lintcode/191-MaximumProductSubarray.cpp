#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> maxdp(n), mindp(n);
        maxdp[0] = mindp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < n; ++i) {
            mindp[i] = min(nums[i], min(maxdp[i-1]*nums[i], mindp[i-1]*nums[i]));
            maxdp[i] = max(nums[i], max(maxdp[i-1]*nums[i], mindp[i-1]*nums[i]));
            result = max(result, maxdp[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
