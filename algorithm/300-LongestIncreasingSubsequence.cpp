#include <iostream>
#include <vector>
using namespace std;

// the famous LIC problem, as well a classical dp problem


// Solution 1 : trivial dp, O(n^2) time, 116ms
// dp[i] represents when end up with nums[i], LIS's length. Its recurrence is :  dp[i] = max{ dp[j]+1 | 0 <j< i and num[j]<num[i] }
int lengthOfLIS_On2(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    int result = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j]+1);
        result = max(result, dp[i]);
    }
    return result;
}


// Solution 2 : O(nlgn) time
// we maintain a array (lis) which lis[i] represents the smallest number of the same length of LIS, so we can use binary search 
// the length of while array is lis's length
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> lis;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it == lis.end()) lis.push_back(nums[i]);
        else *it = nums[i];
    }
    return lis.size();
}


int main() {
    vector<int> nums = {1, 2, 3, 2, 1};
    cout << lengthOfLIS_On2(nums) << endl;
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
