#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



// Solution 1 : dp, O(n^2)
class Solution_dp {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
                else if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


// Solution 2 : greedy, O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int c1 = 1, c2 = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) c1 = c2+1;
            else if (nums[i] < nums[i-1]) c2 = c1+1;
        }
        return max(c1, c2);
    }
};

int main() {
    Solution s;
    vector<int>nums = {1,17,5,10,13,15,10,5,16,8};
    cout << s.wiggleMaxLength(nums) <<endl;
    return 0;
}
