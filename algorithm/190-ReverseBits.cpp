#include <iostream>
#include <bitset>
using namespace std;

// Solution 1 : iterate all bits, set m's last bit with n's last bit, m left rotate, n right rotate
uint32_t reverseBits_it(uint32_t n) {
    uint32_t m = 0;
    for (int i = 0; i < 32; ++i)
        m = (m<<1) | (n>>i & 1);
    return m;
}


// Solution 2 : divide and conquer, like merge sort
// abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
uint32_t reverseBits_dc(uint32_t n) {
    n = (n << 16) | (n >> 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}


// Solution 3 : swap half
uint32_t reverseBits_swap(uint32_t n) {
    for (int i = 0; i < 32>>1; ++i) {
        int j = 32-1-i;
        uint32_t low = (n>>i) & 1;
        uint32_t high = (n>>j) & 1;
        if (low^high) // if low is not equal to high, one of them must be 1, another must be 0, set 1 to 0, set 0 to 1, use ^1
            n ^= (1<<i) | (1<<j); // well done
    }
    return n;
}

int main() {
    cout << reverseBits_it(43261596) << endl;
    cout << reverseBits_dc(43261596) << endl;
    cout << reverseBits_swap(43261596) << endl;
    return 0;
}
