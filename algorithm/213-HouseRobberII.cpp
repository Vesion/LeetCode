#include <iostream>
#include <vector>
using namespace std;

// dp, similiar to 198-HouseRobber
// But something different is that the last house is neighbour of the first one, so our strategy is run dp process two times.
//      The first time we rob house[0], as a result we cannot rob house[n-1] (stop iterating in n-2);
//      The second time we do not rob house[0], as a result, we can rob house[n-1];
//      So the final result is the max of above two.

int dp(vector<int>& nums, int left, int right) {
    int pre = 0, cur = 0;
    for (int i = left; i < right; ++i) {
        int temp = max(pre+nums[i], cur);
        pre = cur;
        cur = temp;
    }
    return cur;
}

int rob(vector<int>& nums) {
    int n = nums.size(); 
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    return max(dp(nums, 0, n-1), dp(nums, 1, n));
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << rob(nums) << endl;
    return 0;
}
