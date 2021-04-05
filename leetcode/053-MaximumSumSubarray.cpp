#include <iostream>
#include <vector>
using namespace std;

// classic DP problem, max sum of subarray
// dp[i] = max{dp[i-1] + nums[i], nums[i]}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            if (sum + num < num) sum = num;
            else sum += num;
            res = max(res, sum);
        }
        return res;
    }
};


int main() {
    return 0;
}
