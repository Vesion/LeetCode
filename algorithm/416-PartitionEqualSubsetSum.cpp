#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <bitset> 
using namespace std;


// Solution 1 : dfs
class Solution {
public:
    bool dfs(vector<int>& nums, int cur, int sum) {
        if (sum == 0) return true;
        if (sum < 0) return false;
        for (int i = cur; i < (int)nums.size(); ++i)
            if (dfs(nums, i+1, sum-nums[i])) return true;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        return sum & 1 ? false : dfs(nums, 0, sum/2);
    }
};


// Solution 2 : dp
class Solution_dp {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum /= 2;
        vector<int> dp(sum+1, 0);
        for (int i = 1; i <= sum; ++i) dp[i] = INT_MIN;
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j)
                dp[j] = max(dp[j-nums[i]]+1, dp[j]);
        }
        return dp[sum] > 0;
    }
};


// Solution 3 : bitset, tricky
class Solution_bit {
public:
    bool canPartition(vector<int>& nums) {
        bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto& num : nums)
            bits |= bits << num;
        return !(sum&1) && bits[sum>>1];
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,5};
    cout << s.canPartition(nums);
    return 0;
}
