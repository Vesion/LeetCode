#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Count the number of 1s in an integer


// Get the least significant 1-bit, minus it till 0
// just like the operation in BIT
int countOnes_1(uint32_t n) {
    int res = 0;
    while (n) {
        n -= (n&-n);
        ++res;
    }
    return res;
}

int countOnes_2(uint32_t n) {
    int r = 0;
    while (n) {
        ++r;
        n &= (n-1);
    }
    return r;
}

int main() {
    cout << countOnes(0xf7ff) << endl;
    return 0;
}
