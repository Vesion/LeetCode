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
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


int main() {
    return 0;
}
