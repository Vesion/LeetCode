#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Doubling
// The question requires not to use long long, use unsigned int.

// use only addition to implement division
class Solution {
public:
    int divide(int a, int b) {
        if (b == 0 || (a == INT_MIN && b == -1)) return INT_MAX;
        bool same = (a^b) >= 0;
        unsigned x = abs(a), y = abs(b), res = 0;
        while (x >= y) {
            unsigned sum = y, count = 1;
            while (sum < (INT_MAX>>1) && sum + sum <= x) {
                sum += sum;
                count += count;
            }
            x -= sum;
            res += count;
        }
        return same ? res : -res;

    }
};


// bitmap
class Solution {
public:
    int divide(int a, int b) {
        if (b == 0 || (a == INT_MIN && b == -1)) return INT_MAX;
        bool same_sign = (a^b) >= 0;
        unsigned x = abs(a), y = abs(b), res = 0;
        for (int i = 31; i >= 0; --i) {
            if ((x>>i) >= y) {
                res |= (1<<i);
                x -= (y<<i);
            }
        }
        return same_sign ? res : -res;
    }
};


int main() {
    return 0;
}
