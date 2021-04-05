#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// number of submatrix sum to k is equal to
// number of prefix sum equal to (sum-k)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[t] = count of prefix array which sum to t
        unordered_map<int,int> dp;
        int sum = 0;
        int res = 0;
        dp[0] = 1;
        for (int num : nums) {
            sum += num;
            if (dp.count(sum-k)) res += dp[sum-k];
            ++dp[sum];
        }
        return res;
    }
};


int main() {
    return 0;
}
