#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, step = 1, num = n;
        bool fromLeft = true;
        while (num > 1) {
            // start will be eliminated only if:
            //      1. this turn goes from left to right
            //      2. this turn goes from right to left, and there are odd number of nums
            // if so, we must add start by step
            if (fromLeft || num & 1) start += step;
            step *= 2;
            num /= 2;
            fromLeft = !fromLeft;
        }
        return start;
    }
};


int main() {
    return 0;
}
