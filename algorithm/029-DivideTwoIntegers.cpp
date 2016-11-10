#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = (dividend > 0 ) ^ (divisor > 0) ? -1 : 1;
        long long ldvd = labs(dividend);
        long long ldvs = labs(divisor);
        int res = 0;
        while (ldvs <= ldvd) {
            long long tmp = ldvs;
            int mul = 1;
            while ((tmp << 1) <= ldvd) {
                tmp <<= 1;
                mul <<= 1;
            }
            ldvd -= tmp;
            res += mul;
        }
        return res * sign;
    }
};

int main() {
    Solution s;
    return 0;
}

