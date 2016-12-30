#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 296-BestMeetingPoint, find the median
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int mid = nums[n/2];
        int res = 0;
        for (int num : nums) res += abs(mid-num);
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
