#include <iostream>
#include <algorithm>
#include <vector>
#include <set> 
#include <numeric> 
#include <string>
using namespace std;

// 'Maximum Sum of Subarray' is a set of dp problems.
// It has many applications and variations, like in leetcode 'The Best Time to Buy and Sell Stock I/II/III/IV'
//
//
// Version 1.1 : Basical, all versions below are variants based on this.
//      Problem: Find the maximum sum of subarray of an array.
//      Solution: dp[i] = max( dp[i]+nums[i], nums[i] )
//                result = max(result, dp[i] )
// Version 1.2 : Product
//      Problem: Find the maximum product sum of subarray.
//      Solution: maxdp[i] = max( max( mindp[i-1]*nums[i], maxdp[i-1]*nums[i] ), nums[i] )
//                mindp[i] = min( min( maxdp[i-1]*nums[i], mindp[i-1]*nums[i] ), nums[i] )
//                result = max( result, maxdp[i] )
//
//
// Version 2 : Sum no larger than K
//      Problem: Find the maximum sum of subarray which is no larger than K
//      Solution: The naive is O(n^2), use binary search to speed up to O(nlogn) (something like the 'Subarray sum equals to 0' problem)
//
//
// Version 3.1 : Two subarrays sum
//      Problem: Find two non-overlapping subarrays which have the largest sum.
//      Solution: Two scans, record leftmax and rightmax respectively
// Version 3.2 : Two subarrays difference
//      Problem: Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.
//      Solution: Similar to 3.1, but we need max and min both
//
//
// Version 4 : Max M subarrays sum !!!
//      Problem: Find m non-overlapping subarrays which have the largest sum.
//      Solution: Hard, dp[i][j] represents the max sum of i subarrays in first j numbers, ending with num[j]
//
//
// Version 5.1 : Max sum sub matrix (2D)
//      Problem: Find the maximum sum of sub matrix in a 2D matrix
//      Solution: Fix row first, process column as 1D version
// Version 5.2 : Max sum sub matrix no larger than K
//      Problem: Find the maximum sum of sub matrix in a 2D matrix which is no larger than K
//      Solution: Combine 5.1 and 2



// Version 1.1
int maxSumSubArray(vector<int> nums) {
    if (nums.empty()) return 0;
    int sum = 0, res = INT_MIN;
    for (int &num :nums) {
        sum = max(sum+num, num);
        res = max(sum, res);
    }
    return res;
}

// Version 1.2
int maxProductSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = INT_MIN;
    int maxp = 1, minp = 1;
    for (int& num : nums) {
        int tmaxp = maxp, tminp = minp;
        maxp = max(num, max(tmaxp*num, tminp*num));
        minp = min(num, min(tmaxp*num, tminp*num));
        res = max(res, maxp);
    }
    return res;
}


// Version 2
int maxSumSubArrayNoLargerThanK(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    set<int> sums;
    sums.insert(0);
    int sum = 0, result = INT_MIN;
    for (auto &num : nums) {
        sum += num;
        auto it = sums.lower_bound(sum-k); // binary search
        if (it != sums.end()) result = max(result, sum-*it);
        sums.insert(sum);
    }
    return result;
}


// Version 3.1
int maxSumTwoSubArrays(vector<int> nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> leftMax(n), rightMax(n);
    int local;

    local = leftMax[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        local = max(local+nums[i], nums[i]);
        leftMax[i] = max(leftMax[i-1], local);
    }

    local = rightMax[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; --i) {
        local = max(local+nums[i], nums[i]);
        rightMax[i] = max(rightMax[i+1], local);
    }

    int result = INT_MIN;
    for (int i = 0; i < n-1; ++i) {
        result = max(result, leftMax[i]+rightMax[i+1]);
    }
    return result;
}

// Version 3.2
int maxDiffTwoSubArrays(vector<int> nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    int localMax, localMin;

    vector<int> leftMax(n), leftMin(n);
    localMax = localMin = leftMax[0] = leftMin[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        localMax = max(localMax+nums[i], nums[i]);
        localMin = min(localMin+nums[i], nums[i]);
        leftMax[i] = max(leftMax[i-1], localMax);
        leftMin[i] = min(leftMin[i-1], localMin);
    }

    vector<int> rightMax(n), rightMin(n);
    rightMax[n-1] = rightMin[n-1] = localMax = localMin = nums[n-1];
    for (int i = n-2; i >= 0; --i) {
        localMax = max(localMax+nums[i], nums[i]);
        localMin = min(localMin+nums[i], nums[i]);
        rightMax[i] = max(rightMax[i+1], localMax);
        rightMin[i] = min(rightMin[i+1], localMin);
    }

    int result = 0;
    for (int i = 0; i < n-1; ++i) {
        result = max(result, max(abs(leftMax[i]-rightMin[i+1]), abs(rightMax[i+1]-leftMin[i])));
    }
    return result;
}


// Version 4
// dp[i][j] is the max sum of i subarrays of first j numbers, ending with num[j]
//      dp[i][j] = max { dp[i][j-1]+num[j], dp[i-1][t]+num[j] | i-1 <= t <= j-1 }
//      result = max { dp[m][j], 1 <= j <= n }
// The direct solution is O(m*n^2) time, we can do some optimizations to reduce to O(m*n)
// http://blog.csdn.net/liufeng_king/article/details/8632430
// http://www.cnblogs.com/dongsheng/archive/2013/05/28/3104629.html
//
int maxSumMSubArrays(vector<int> nums, int m) {
    int n = nums.size();
    if (n*m == 0 || n < m) return 0;
    vector<int> c(n+1, 0); // c[j] = dp[i][j]
    vector<int> p(n+1, 0); // p[j] = max{ dp[i-1][t] | t <= j }

    int maxsum;
    for (int i = 1; i <= m; ++i) {
        maxsum = INT_MIN;
        for (int j = i; j <= n; ++j) {
            c[j] = max(c[j-1], p[j-1]) + nums[j-1];
            p[j-1] = maxsum;
            maxsum = max(maxsum, c[j]);
        }
        p[n] = maxsum;
    }
    return maxsum;
}
int maxSumMSubArrays_2(vector<int> nums, int m) {
    int n = nums.size();
    if (n*m == 0 || n < m) return 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; ++i) {
        int preMax = dp[i-1][i-1];
        for (int j = i; j <= n; ++j) {
            if (j > i) dp[i][j] = max(dp[i][j-1]+nums[j-1], preMax+nums[j-1]);
            else dp[i][j] = preMax+nums[j-1];
            preMax = max(preMax, dp[i-1][j]);
        }
    }
    int res = INT_MIN;
    for (int i = m; i <= n; ++i) res = max(res, dp[m][i]);
    return res;
}


// Version 5
int maxSumSubMatrix2D(vector<vector<int>>& nums) {
    if (nums.empty()) return 0;
    int result = 0;
    int m = nums.size(), n = nums[0].size();
    for (int r1 = 0; r1 < m; ++r1) {
        vector<int> rowsum(n, 0);
        for (int r2 = r1; r2 < m; ++r2) {
            int dp = 0;
            for (int c = 0; c < n; ++c) {
                rowsum[c] = (r1 == r2 ? nums[r1][c] : rowsum[c]+nums[r2][c]);
                dp = max(dp+rowsum[c], rowsum[c]);
                result = max(result, dp);
            }
        }
    }
    return result;
}


int main() {
    cout << maxSumMSubArrays({2, 3, -7, 6, 4, -5}, 3) <<endl;
    return 0;
}
