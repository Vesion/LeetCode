#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy
// https://discuss.leetcode.com/topic/45320/c-8ms-greedy-solution-with-explanation
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxNum = 0;
        int i = 0;
        int res = 0;
        while (maxNum < n) {
            if (i < (int)nums.size() && nums[i] <= maxNum+1) {
                maxNum += nums[i++];
            } else {
                maxNum += maxNum+1;
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

