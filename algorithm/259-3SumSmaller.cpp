#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i+2 < n; ++i) {
            int t = target-nums[i];
            int j = i+1, k = n-1;
            while (j < k) {
                if (nums[j]+nums[k] < t) { res += k-j; ++j; }
                else --k;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
