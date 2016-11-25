#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 0来自于因子5*2，2的个数是足够的，只需要数出n!中因子5的个数
// 1...n中，每个5的倍数提供一个5，每个5^2的倍数在之前的基础上再额外提供一个5，每个5^3的倍数再额外提供一个5....
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

