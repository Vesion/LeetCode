#include <iostream>
#include <vector>
using namespace std;

// the famous LIC problem, as well a classical dp problem


// Solution 1 : trivial dp, O(n^2) time, 116ms
// dp[i] represents when end up with nums[i], LIS's length. Its recurrence is :  dp[i] = max{ dp[j]+1 | 0 <j< i and num[j]<num[i] }
class Solution_1 {
public:
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
};


// Solution 2 : O(nlgn) time
// we maintain a array (lis) which lis[i] represents the smallest number of the same length of LIS, so we can use binary search 
// the length of while array is lis's length
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) lis.push_back(num);
            else *it = num;
        }
        return lis.size();
    }
};


int main() {
    return 0;
}
