#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(n)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) | (n&1);
            n >>= 1;
        }
        return res;
    }
};


// Solution 2 : O(logn)
class Solution_2 {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};


int main() {
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    return 0;
}

