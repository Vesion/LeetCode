#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n&(n-1)) == 0);
    }
};


int main() {
    return 0;
}
