#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <bitset> 
using namespace std;

// The famous 'Subset Sum Problem'

// Solution 1 : dp, similar to '01-knapsack'
// This solution can not only solve 'if it can' problem, but 'how many solutions' problem
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1) return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int& num : nums) {
            for (int j = sum; j >= num; --j) {
                dp[j] = dp[j] | dp[j-num];
            }
        }
        return dp[sum];
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
