#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor2 = 0;
        for (int num : nums) xor2 ^= num;
        int t = xor2 & -xor2;
        vector<int> res(2, 0);
        for (int num : nums) {
            if (t&num) res[0] ^= num;
            else res[1] ^= num;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
