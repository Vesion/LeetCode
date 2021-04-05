#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// naive bfs, TLE


// grey code
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/discuss/877798/JavaC%2B%2BPython-3-Solutions-with-Prove-O(1)-Space
class Solution0 {
public:
    unordered_map<int,int> dp;
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];
        int b = 1;
        while ((b<<1) <= n) b <<= 1;
        return dp[n] = minimumOneBitOperations(((b>>1)^b) ^ n) + 1 + (b-1);
    }
};

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        for (; n > 0; n &= (n-1)) {
            res = -(res + (n ^ (n-1)));
        }
        return abs(res);
    }
};


int main() {
}