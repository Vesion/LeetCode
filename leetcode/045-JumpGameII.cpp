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
        int max_end = 0, end = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > end) {
                end = max_end;
                ++res;
            }
            max_end = max(max_end, i+nums[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.jump(nums) << endl;
    return 0;
}
