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
        if (nums.empty() || m == 0) return 0;
        int left = 0, right = 0;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (!canSplit(nums, mid, m)) left = mid+1; // if cannot split, it means upper is too small
            else right = mid-1;
        }
        return left;
    }

    // check if nums can be split into m subarrays with largest one's sum no greater than upper
    // or, given upper sum, check if it can be split into no more than m subarrays
    bool canSplit(vector<int>& nums, int upper, int m) {
        int sum = 0;
        int c = 1;
        for (int num : nums) {
            sum += num;
            if (sum > upper) {
                ++c;
                sum = num;
            }
        }
        return c <= m;
    }
};


// Solution 2 : dp, O(n^3), TLE
// but this one is more general, numbers can be negative here.
//
// dp[s,j] is the solution for splitting subarray n[j]...n[L-1] into s parts.
// dp[s+1,i] = min{ max(dp[s,j], n[i]+...+n[j-1]) }, i+1 <= j <= L-s
//
class Solution_2 {
public:
    using ll = long long;
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<ll> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + nums[i-1];

        vector<ll> dp(n, 0);
        for (int i = 0; i < n; ++i) dp[i] = sums[n]-sums[i]; // dp[i] = nums[i+1] + nums[i+2] + ... + nums[n-1]

        for (int s = 1; s < m; ++s) {
            for (int i = 0; i < n-s; ++i) {
                dp[i] = LONG_MAX;
                for (int j = i+1; i <= n-s; ++j) {
                    ll tmp = max(dp[j], sums[j]-sums[i]);
                    if (tmp <= dp[i]) dp[i] = tmp;
                    else break;
                }
            }
        }
        return dp[0];
    }
};



int main() {
    Solution s;
    return 0;
}

