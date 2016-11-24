#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int result = nums[0];
        vector<int> dpmax(n, 0), dpmin(n, 0);
        dpmax[0] = dpmin[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dpmax[i] = max(max(dpmax[i-1]*nums[i], dpmin[i-1]*nums[i]), nums[i]);
            dpmin[i] = min(min(dpmax[i-1]*nums[i], dpmin[i-1]*nums[i]), nums[i]);
            result = max(result, dpmax[i]);
        }
        return result;
    }
};

int main() {
    return 0;
}
