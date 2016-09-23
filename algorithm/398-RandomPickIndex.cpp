#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> nums;

    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int index = -1;
        int c = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == target) {
                ++c;
                if (rand() % c == 0) index = i;
            }
        }
        return index;
    }
};

int main() {
    Solution s({1, 2, 3, 3, 3});
    for (int i = 0; i < 8000; ++i) { 
        s.pick(3);
    } 
    return 0;
}
