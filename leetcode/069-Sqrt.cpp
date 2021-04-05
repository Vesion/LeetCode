#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : binary search
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 1, right = x/2;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (mid == x / mid) return mid;
            if (mid > x / mid) right = mid-1;
            else left = mid+1;
        }
        return right; // why return right rather than left, bacause sqrt round down
    }
};


// Solution 2 : bit manipulation
class Solution_2 {
public:
    int mySqrt(int x) {
        int bit = 1 << 16;
        int res = 0;
        while (bit) {
            res |= bit;
            if (res > x/res) res ^= bit;
            bit >>= 1;
        }
        return res;
    }
};


int main() {
    Solution_2 s;
    cout << s.mySqrt(0);
    return 0;
}

