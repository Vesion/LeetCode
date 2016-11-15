#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= reach) reach = max(reach, i+nums[i]);
        }
        return reach >= n-1;
    }
};

int main() {
    Solution s;
    return 0;
}

