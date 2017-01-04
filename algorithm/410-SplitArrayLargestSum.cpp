#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
#include <string>
using namespace std;

// Solution 1 : binary search
// This elegant solution takes good advantage of the 'all numbers are positive' property.
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (canSplit(nums, m, mid)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }

    // check if nums can be split into m subarrays with largest one's sum no greater than upper
    // or, given upper sum, check if it can be split into no more than m subarrays
    bool canSplit(vector<int>& nums, int m, int upper) {
        int sum = 0, count = 1;
        for (int num : nums) {
            sum += num;
            if (sum > upper) {
                ++count;
                sum = num;
            }
        }
        return count <= m;
    }
};


// Solution 2 : dp, O(m*n^2), TLE
// but this one is more general, numbers can be negative here.
//
// dp[s][i] is the solution for splitting nums[0...i] into s subarrays
//      dp[s][i] = min( max(dp[s-1][j], nums[j+1] + ... + nums[i]) ), s-1 <= j <= i-1
//
// our target is dp[m][n-1]
class Solution_2 {
public:
    using ll = long long;
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<ll> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + nums[i-1];

        vector<vector<ll>> dp(m+1, vector<ll>(n));
        for (int i = 0; i < n; ++i) dp[1][i] = sums[i+1];

        for (int s = 2; s <= m; ++s) {
            for (int i = 1; i < n; ++i) {
                dp[s][i] = LONG_MAX;
                for (int j = s-2; j <= i-1; ++j) { // be careful with j's range
                    dp[s][i] = min(dp[s][i], max(dp[s-1][j], sums[i+1]-sums[j+1]));
                }
            }
        }
        return dp[m][n-1];
    }
};


int main() {
    Solution_2 s2;
    vector<int> nums = {1,5,6,7,8,19,32,0,3};
    cout << s2.splitArray(nums, 2) <<endl;
    return 0;
}

