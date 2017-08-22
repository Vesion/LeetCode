#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n &= (n-1);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

