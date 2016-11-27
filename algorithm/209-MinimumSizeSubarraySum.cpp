#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// Solution 1 : sliding window, O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int res = INT_MAX;
        int sum = 0;
        while (right < (int)nums.size()) {
            sum += nums[right++];
            while (sum >= s) {
                res = min(res, right-left);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};


// Solution 2 : binary search, O(nlogn)
class Solution_2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n+1, 0);
        partial_sum(nums.begin(), nums.end(), sums.begin()+1);
        int minlen = INT_MAX;
        for (int i = 1; i <= n; i++) { 
            if (sums[i] >= s) {
                int p = upper_bound(sums, 0, i, sums[i] - s);
                if (p != -1) minlen = min(minlen, i - p + 1);
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }

    int upper_bound(vector<int>& sums, int left, int right, int target) {
        int l = left, r = right;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (sums[m] <= target) l = m + 1;
            else r = m;
        }
        return sums[r] > target ? r : -1;
    }
};


int main() {
    Solution s;
    vector<int> n = {1,2,3,4,5};
    cout << s.minSubArrayLen(11, n) << endl;
    return 0;
}

