#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int res = 0;
        while (x) {
            x &= (x-1);
            ++res;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
