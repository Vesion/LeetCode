#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) res ^= num;
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

