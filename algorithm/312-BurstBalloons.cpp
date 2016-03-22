#include <iostream>
#include <vector>
using namespace std;

// What I thought about and why I gave up:
//      1. Brute-force, what we need to do is burst n balloons, so the optimal result is decided by sequence of n. So brute-force need all n! permutation, that's not reality.
//      2. Can we use dp or memorization to utilize space to get faster? It turns out just a little better, but worse than O(2^n).
//      3. According to the hint, how about divide-and-conquer,  the nature way to divide the problem is burst one balloon and separate the balloons into 2 sub sections one on the left and one one the right. However, in this problem the left and right become adjacent and have effects on the maxCoins in the future.
// Here so far, I gave up...

// What real matters is we should reverse our mind, look at the last burst balloon!
// Instead of divide the problem by the first balloon to burst, we divide the problem by the last balloon to burst. 
// Think about n balloons if i is the last one to burst, we can see that the balloons is again separated into 2 sections. But this time since the balloon i is the last balloon of all to burst, the left and right section now has well defined boundary and do not affect each other! 
// Therefore we can do either recursive method with memoization or dp.


// Solution 1 : divide-and-conquer + memoization, O(n^3) time
int burst(vector<int>& nums, int left, int right, vector<vector<int>>& memo) {
    if (left + 1 == right) return 0;
    if (memo[left][right]) return memo[left][right];
    int result = 0;
    for (int i = left+1; i < right; ++i)
        result = max(result, burst(nums, left, i, memo) + burst(nums, i, right, memo) + nums[left]*nums[i]*nums[right]); // divided by the last burst balloon
    memo[left][right] = result;
    return result;
}

int maxCoins_memo(vector<int>& nums) {
    if (nums.empty()) return 0;
    nums.insert(nums.begin(), 1), nums.push_back(1); // add the nums[-1] and nums[n]
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n, 0));
    return burst(nums, 0, n-1, memo);
}


// Solution 2 : dp, O(n^3) time
int maxCoins_dp(vector<int>& nums) {
    if (nums.empty()) return 0;
    nums.insert(nums.begin(), 1), nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; ++len) {
        for (int left = 0; left < n-len; ++left) {
            int right = left + len;
            for (int i = left+1; i < right; ++i)
                dp[left][right] = max(dp[left][right], 
                        dp[left][i] + nums[left]*nums[i]*nums[right] + dp[i][right]); // ditto, divided by the last burst balloon
        }
    }
    return dp[0][n-1];
}


int main() {
    vector<int> nums = {3, 1, 5, 8};
    //cout << maxCoins_memo(nums) << endl;
    cout << maxCoins_dp(nums) << endl;
    return 0;
}
