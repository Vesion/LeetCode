#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <bitset> 
using namespace std;

// Solution 1 : dp, similar to 'complete knapsack'
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1) return false;
        sum >>= 1;

        vector<int> dp(sum+1, INT_MIN);
        dp[0] = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j-nums[i]]+1);
            }
        }
        return dp[sum] > 0;
    }
};


// Solution 2 : hash table, use tricky bitmap
// record each sum, and check total_sum/2 finally
class Solution_2 {
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
