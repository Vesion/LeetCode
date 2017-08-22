#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityNumber(vector<int> nums) {
        int count = 1, result = 0;
        for (auto &num : nums) {
            if (num == result)
                ++count;
            else if (count == 0) {
                count = 1;
                result = num;
            }
            else --count;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1, 2,  2, 2, 2};
    cout << s.majorityNumber(nums) << endl;
    return 0;
}
