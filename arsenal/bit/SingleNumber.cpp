#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// A general problem:
//      Every element appears k times, except for one appears p times, find it.
//
//
// A general solution for all these kind of problems, Orz
// https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/2
//
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
    for (int& num : nums) {
        x3 ^= x2 & x1 & num;
        x2 ^= x1 & num;
        x1 ^= num;
        mask = ~(x1 & ~x2 & x3); // because k = 0b101
        x3 &= mask;
        x2 &= mask;
        x1 &= mask;
    }
    return x1;  // p = 3, in binary form p = '0b11', then p1 = p2 = 1, so we return x1 or x2
}

int main() {
    vector<int> nums = {3,2,3,2,3,3,3,2};
    cout << singleNumber(nums) << endl;
    return 0;
}
