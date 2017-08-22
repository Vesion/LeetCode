#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return false;
        int reach = nums[0];
        for (int i = 1; i < n; ++i) {
            if (reach < i) return false;
            if (reach >= n-1) return true;
            reach = max(reach, i+nums[i]);
        }
        return true; // never
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,1,0,4};
    cout << s.canJump(nums) << endl;
    return 0;
}
