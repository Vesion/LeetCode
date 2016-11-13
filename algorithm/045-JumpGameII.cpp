#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Explanation 1 : BFs, points in level i are those can be reached from level i-1
// Explanation 2 : Greedy, jump to farthest point each time
class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, end = 0; // farthest is the farthest point jump from [start, end] can reach
        int level = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > end) {
                end = farthest;
                ++level;
            }
            farthest = max(farthest, i+nums[i]);
        }
        return level;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.jump(nums) << endl;
    return 0;
}

