#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int dp = 0, result = INT_MIN;
        for (auto &num :nums) {
            dp = max(dp+num, num);
            result = max(dp, result);
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
