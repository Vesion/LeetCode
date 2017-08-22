#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumberIII(vector<int> &nums) {
        int m = 0;
        for (auto & num : nums) m ^= num;
        m &= -m;
        vector<int> result(2, 0); 
        for (auto & num : nums) {
            if (num & m) result[0] ^= num;
            else result[1] ^= num;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,2,3,4,4,5,3};
    auto r = s.singleNumberIII(nums);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}
