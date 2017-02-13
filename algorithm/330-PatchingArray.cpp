#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int i = 0;
        int res = 0;
        while (sum < n) {
            if (i < (int)nums.size() && nums[i] <= sum+1) { // next number in nums is in range
                sum += nums[i++]; // add a number in nums
            } else {
                sum += sum+1; // patch a new number 'sum+1'
                ++res;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 2};
    cout << s.minPatches(nums, 16) << endl;
    return 0;
}
