#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dp, O(n^2)
class Solution_1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<pair<int,int>> dp(n);
        dp[0].first = dp[0].second = 1;
        int res = 0;
        for (int i = 1; i < n; ++i) {
            dp[i].first = dp[i].second = 1;
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] > nums[j]) dp[i].first = max(dp[i].first, dp[j].second+1);
                else if (nums[i] < nums[j]) dp[i].second = max(dp[i].second, dp[j].first+1);
            }
            res = max(res, max(dp[i].first, dp[i].second));
        }
        return res;
    }
};


// Solution 2 : greedy
// Maintain a longest wiggle sequence, for each num, reset it to min when down, or max when up.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int up = 1, down = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) up = down+1;
            else if (nums[i] < nums[i-1]) down = up+1;
        }
        return max(up, down);
    }
};


int main() {
    Solution s;
    vector<int> nums = {0,0};
    cout << s.wiggleMaxLength(nums) << endl;
    return 0;
}

