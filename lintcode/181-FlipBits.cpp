#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int bitSwapRequired(int a, int b) {
        int i = a ^ b;
        int c = 0;
        while (i) {
            i &= i-1;
            ++c;
        } 
        return c;
    }
};

int main() {
    Solution s;
    cout << s.bitSwapRequired(0, 1) << endl;
    return 0;
}
