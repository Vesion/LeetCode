#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 136-SingleNumber, but here we need to simulate ternary
// So we need two bits, ones and twos:
//      00 -> 10 -> 01 -> 00 (0 -> 1 -> 2 -> 3/0)
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


// A more general solution for all these kind of problems, Orz
// https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/2
//
// A general problem:
//      Every element appears k times, except for one appears p times
//
// The main process has three steps:
//      1. we need m counters (32-bit integer) to count for k times, 2^m >= k
//      2. use ^ to count and do carry, if k < 2^m, we also need a mask to reset to 0 when reach k
//          mask = ~(y1 & y2 & ... & ym), where yj = xj if kj = 1 and yj = ~xj if kj = 0 (j = 1 to m).
//      3. after scanning all elements, which counter should we return?
//          let p' = p%k, write p' in binary form: p'm, ..., p'2, p'1
//          we return xj as long as p'j = 1
//
// e.g. k = 5, p = 3
int singleNumber(vector<int>& nums) {
    int x1 = 0, x2 = 0, x3  = 0; // we need 3 counters, 2^3 > 5
    int mask = 0; // we need mask, because 2^3 != 5
    for (int& i : nums) {
        x3 ^= x2 & x1 & i;
        x2 ^= x1 & i;
        x1 ^= i;
        mask = ~(x1 & ~x2 & x3); // because k = 0b101
        x3 &= mask;
        x2 &= mask;
        x1 &= mask;
    }
    return x1;  // p = 3, in binary form p = '0b11', then p1 = p2 = 1, so we return x1 or x2
}


int main() {
    return 0;
}

