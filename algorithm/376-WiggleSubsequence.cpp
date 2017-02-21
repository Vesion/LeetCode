#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dp, O(n^2)
class Solution_1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int res = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] > nums[j]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
                else if (nums[i] < nums[j]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};


// Solution 2 : greedy, skillful
// https://discuss.leetcode.com/topic/51946/very-simple-java-solution-with-detail-explanation
// Maintain a longest wiggle sequence, for each num, reset it to min when down, or max when up.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int inc = 1, dec = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] > nums[i-1]) inc = dec+1;
            else if (nums[i] < nums[i-1]) dec = inc+1;
        }
        return max(inc, dec);
    }
};


int main() {
    return 0;
}
