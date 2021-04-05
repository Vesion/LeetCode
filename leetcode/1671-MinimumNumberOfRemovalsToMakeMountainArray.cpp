#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// get LIS from begin to end, then get LIS from end to begin
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        vector<int> lis;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (it == lis.end()) lis.push_back(nums[i]);
            else *it = nums[i];
            left[i] = lis.size();
        }
        lis.clear();
        for (int i = n-1; i >= 0; --i) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (it == lis.end()) lis.push_back(nums[i]);
            else *it = nums[i];
            right[i] = lis.size();
        }

        int res = 0;
        for (int i = 1; i < n-1; ++i) {
            if (left[i] > 1 && right[i] > 1)
                res = max(res, left[i]+right[i]-1);
        }
        return n-res;
    }
};

int main() {

}
