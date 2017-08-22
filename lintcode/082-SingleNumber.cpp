#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (auto & i : nums) result ^= i;
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,2,1,3,4,3};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
