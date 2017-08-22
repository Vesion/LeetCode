#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 1 : naive, use an array bits to store 32 binary sets
class Solution {
public:
    int singleNumberII(vector<int> &nums) {
        int bits[32] = {0};
        for (auto & num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num >> i & 1) ++bits[i];
                bits[i] %= 3;
            }
        }

        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i]) result |= (1 << i);
        }
        return result;
    }
};


// Solution 2 : use two ints to simulate ternary representation
class Solution_2 {
public:
    int singleNumberII(vector<int> &nums) {
        int ones = 0, twos = 0;
        for (auto & num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main() {
    vector<int> nums = {1,1,2,3,3,3,2,2,4,1};

    Solution s;
    cout << s.singleNumberII(nums) << endl;

    Solution_2 s2;
    cout << s2.singleNumberII(nums) << endl;
    return 0;
}
