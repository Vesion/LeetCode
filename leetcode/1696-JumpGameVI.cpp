#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, O(n*k), TLE
class Solution0 {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i-j >= 0 && j <= k; ++j) {
                dp[i] = max(dp[i], dp[i-j]+nums[i]);
            }
        }
        return dp[n-1];
    }
};


// mono-decreasing queue
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> q;
        for (int i = 0; i < n; ++i) {
            int t = q.empty() ? nums[i] : q.front().second + nums[i];
            while (!q.empty() && t > q.back().second) q.pop_back();
            q.push_back({i, t});
            if (i - q.front().first >= k) q.pop_front();
        }
        return q.back().second;
    }
};


int main() {
}
