#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <bitset> 
using namespace std;

// The famous 'Subset Sum Problem'

// Solution 1 : standard dp
// This solution can not only solve 'if it can' problem, but 'how many solutions' problem
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1) return false;
        sum /= 2;
        vector<int> dp(sum+1, 0); // dp[i] = the number of subsets whose sum is i
        dp[0] = 1;
        for (int& num : nums) {
            for (int i = sum; i >= num; --i) {
                dp[i] += dp[i-num];
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
