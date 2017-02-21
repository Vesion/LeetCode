#include <iostream>
#include <vector>
using namespace std;

// classic DP problem, 最大子段和问题
// dp[i] = max{dp[i-1] + nums[i], nums[i]}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for (int& num : nums) {
            sum = max(sum+num, num);
            res = max(res, sum);
        }
        return res;
    }
};


int main() {
    return 0;
}
