#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset> 
using namespace std;

class Solution {
public:
    int updateBits(int n, int m, int i, int j) {
        int z = 1;
        for (int k = 1; k <= j-i; ++k) {
            z <<= 1;
            z |= 1;
        }
        z <<= (i);
        n &= ~(z);
        return n | (m <<= i);
    } 
};

int main() {
    Solution s;
    int r = s.updateBits(0,0xf,1, 4);
    cout << bitset<32>(r) << endl;
    cout << r << endl;
    return 0;
}
