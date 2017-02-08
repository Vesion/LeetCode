#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (int num : nums) if ((num >> i) & 1) ++ones;
            res += ones * (n-ones);
        }
        return res;
    }
};


int main() {
    return 0;
}
