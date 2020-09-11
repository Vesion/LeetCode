#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

// Similar to 410-SplitArrayLargestSum.cpp

// Binary search, O(n*logS), S is the sum of all nums
class Solution {
public:
    int maximizeSweetness(vector<int>& nums, int K) {
        ++K;
        int lower = numeric_limits<int>::max(), upper = 0;
        for (int num : nums) {
            lower = min(lower, num);
            upper += num;
        }
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (split(nums, K, mid)) lower = mid+1;
            else upper = mid-1;
        }
        return upper;
    }

    // check if can split into k subarrays
    // return true if min(sums) >= t
    bool split(const vector<int>& nums, int k, int t) {
        int c = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            if (sum >= t) { ++c; sum = 0; }
        }
        return c >= k;
    }
};

// DP, O(n^3), TLE
class Solution0 {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        ++K;
        const int n = sweetness.size();
        vector<int> sums = sweetness;
        for (int i = 1; i < n; ++i) sums[i] += sums[i-1];

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < n; ++i) dp[i][1] = sums[i];

        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[i][k] = 0;
                for (int j = k-1; j <= i; ++j) {
                    dp[i][k] = max(dp[i][k], min(dp[j-1][k-1], sums[i]-sums[j-1]));
                }
            }
        }
        return dp[n-1][K];
    }
};


int main() {
}
