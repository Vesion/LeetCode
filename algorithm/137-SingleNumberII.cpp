#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 136-SingleNumber, but here we need to simulate ternary
// So we need two bits, ones and twos:
//      00 -> 01 -> 10 -> 00 (0 -> 1 -> 2 -> 3/0)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main() {
    Solution s;
    return 0;
}

