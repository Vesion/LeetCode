#include <iostream>
#include <vector>
using namespace std;

// dp
// 类似于053题求最大子段和，不同的是这题需要两个dp数组，一个用来记录当前最大乘积，一个用来记录当前最小乘积，因为最小乘积乘负数可能变最大乘积
// 不需要分类讨论，那样反而变复杂
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
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

int main() {
    vector<int> nums = {0, 2};
    cout << maxProduct(nums) << endl;
    return 0;
}
