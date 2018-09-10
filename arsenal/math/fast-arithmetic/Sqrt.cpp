#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : binary search
int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 1, right = x/2;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (mid == x / mid) return mid;
        if (mid > x / mid) right = mid-1;
        else left = mid+1;
    }
    return right;
}


// Solution 2 : bit manipulation
int mySqrt_bit(int x) {
    int bit = 1 << 16;
    int res = 0;
    while (bit) {
        res |= bit;
        if (res > x/res)
            res ^= bit;
        bit >>= 1;
    }
    return res;
}


int main() {
    cout << mySqrt(0);
    return 0;
}

