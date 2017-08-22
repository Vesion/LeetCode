#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityNumber(vector<int> nums) {
        int c1 = 0, r1 = 0, c2 = 0, r2= 1;
        for (auto & num : nums) {
            if (num == r1) ++c1;
            else if (num == r2) ++c2;
            else if (c1 == 0) { c1 = 1; r1 = num; }
            else if (c2 == 0) { c2 = 1; r2 = num; }
            else --c1, --c2;
        }

        c1 = c2 = 0;
        for (auto & num : nums) {
            if (num == r1) ++c1;
            else if (num == r1) ++c2;
        }
        return (c1 > (int)nums.size()/3) ? r1 : r2;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,1,2,2,3,3,4,4,4};
    cout << s.majorityNumber(nums) << endl;
    return 0;
}
