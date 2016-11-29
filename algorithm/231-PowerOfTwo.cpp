#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n-1));
    }
};

int main() {
    Solution s;
    return 0;
}
