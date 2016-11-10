#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        if (left == nums.end() || *left != target) return {-1, -1};
        auto right = upper_bound(nums.begin(), nums.end(), target);
        return {int(left-nums.begin()), int(right-nums.begin()-1)};
        
    }
};

int main() {
    Solution s;
    return 0;
}

