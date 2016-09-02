#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Trivial DP solution, O(n^2) time, similar to LIS.
// Havn't found better solutions.
// 
// Learn to 'pre' vector to construct result.
//
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};    
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        int maxc = 0, maxi = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
                if (dp[i] > maxc) {
                    maxc = dp[i], maxi = i;
                }
            }
        }

        vector<int> result;
        while (maxi >= 0) {
            result.push_back(nums[maxi]);
            maxi = pre[maxi];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1};
    auto r = s.largestDivisibleSubset(nums);
    for (auto& i : r) cout << i << " "; cout<<endl;
    return 0;
}
