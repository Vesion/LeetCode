#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        int small = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) res += (num-small);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 6, 6};
    cout << s.minMoves(nums) << endl;
    return 0;
}

