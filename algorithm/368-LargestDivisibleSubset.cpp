#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DP, O(n^2) time, O(2n) space
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1); // max length of subset for nums[0...i]
        vector<int> pre(n, -1); // previous index of i for dp[i]
        int maxLen = 1, last = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i]; last = i;
            }
        }
        
        vector<int> res;
        while (last != -1) {
            res.push_back(nums[last]);
            last = pre[last];
        }
        return res;
    }
};


int main() {
    return 0;
}

