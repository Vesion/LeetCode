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
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1); // dp[i] means the max length of valid sequence ending with nums[i]
        vector<int> pre(n, -1); // the previous indexes of current valid sequence, for constructing at last
        int maxLen = 0, maxIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        vector<int> res;
        while (maxIndex >= 0) {
            res.push_back(nums[maxIndex]);
            maxIndex = pre[maxIndex];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    auto r = s.largestDivisibleSubset(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

