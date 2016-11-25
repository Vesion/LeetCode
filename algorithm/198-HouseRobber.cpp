#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, notrob = 0;
        for (int num : nums) {
            int tmp = notrob;
            notrob = max(rob, notrob); // if not rob current house, we get max of previous notrob and rob
            rob = tmp + num; // if rob current house, we get previous notrob + current money
        }
        return max(rob, notrob);
    }
};


// Solution 2 : O(n) space
class Solution_2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        return dp[n-1];
    }
};

int main() {
    Solution s;
    return 0;
}

