#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // l[i] = the minimum length of subarray whose sum is target
        //        and is to the left of i, i.e. lies in arr[0...i]
        vector<int> l = left(arr, target);
        // l[i] = the minimum length of subarray whose sum is target
        //        and is to the right of i, i.e. lies in arr[i...n-1]
        vector<int> r = right(arr, target);
        int res = INT_MAX;
        for (int i = 0; i < n-1; ++i)
            res = min(res, l[i]+r[i+1]);
        return res > n ? -1 : res;
    }

    vector<int> left(const vector<int>& a, int target) {
        int n = a.size();
        vector<int> dp(n, n+1);
        int sum = 0;
        for (int i = 0, j = 0; i < n && j <= i; ++i) {
            sum += a[i];
            while (sum > target && j < i) sum -= a[j++];
            if (sum == target) {
                if (i == 0) dp[i] = 1;
                else dp[i] = min(dp[i-1], i-j+1);
            } else {
                if (i > 0) dp[i] = dp[i-1];
            }
        }
        return dp;
    }
    vector<int> right(const vector<int>& a, int target) {
        int n = a.size();
        vector<int> dp(n, n+1);
        int sum = 0;
        for (int i = n-1, j = n-1; i >= 0 && i <= j; --i) {
            sum += a[i];
            while (sum > target && i < j) sum -= a[j--];
            if (sum == target) {
                if (i == n-1) dp[i] = 1;
                else dp[i] = min(dp[i+1], j-i+1);
            } else {
                if (i < n-1) dp[i] = dp[i+1];
            }
        }
        return dp;
    }
};

int main() {
    return 0;
}

