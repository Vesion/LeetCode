#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Reservoir Sampling algorithm
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int count = 0;
        int res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == target) {
                if (rand() % ++count == 0) res = i;
            }
        }
        return res;
    }
};

int main() {
    Solution s({1, 2, 3, 3, 3});
    for (int i = 0; i < 8000; ++i) {
        s.pick(3);
    }
    return 0;
}
