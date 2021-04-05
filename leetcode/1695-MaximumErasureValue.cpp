#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, sum = 0;
        constexpr int kMax = 1e4+5;
        vector<bool> m(kMax, false);
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            while (m[nums[j]]) {
                sum -= nums[i];
                m[nums[i++]] = false;
            }
            sum += nums[j];
            m[nums[j]] = true;
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
}
