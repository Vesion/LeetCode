#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> res(n);
        int val = (1 << maximumBit) - 1;
        for (int i = 0; i < n; ++i)
            res[n - i - 1] = val ^= nums[i];
        return res;
    }
};

int main() {

}