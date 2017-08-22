#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        int n = nums.size();
        if (n < 3) return target;
        sort(nums.begin(), nums.end());
        int result = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i]+nums[j]+nums[k];
                if (abs(sum-target) < abs(result-target)) result = sum;
                if (sum < target) ++j;
                else --k; // sum >= target
            }
        }
        return result;;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {-1, -1, 1, 1};
    cout << s.threeSumClosest(nums, -1) << endl;
    return 0;
}
