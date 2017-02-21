#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(rob(nums, 0, n-1), rob(nums, 1, n));
    }
    
    int rob(vector<int>& nums, int start, int end) {
        int rob = 0, notrob = 0;
        for (int i = start; i < end; ++i) {
            int t = notrob;
            notrob = max(rob, notrob);
            rob = t + nums[i];
        }
        return max(rob, notrob);
    }
};


int main() {
    return 0;
}
