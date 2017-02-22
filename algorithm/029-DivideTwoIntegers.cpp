#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// use only addition to implement division, binary search
class Solution {
public:
    using ll = long long;

    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        ll ldvd = labs(dividend), ldvs = labs(divisor);
        int res = 0;
        while (ldvs <= ldvd) {
            ll sum = ldvs;
            int count = 1;
            while (sum + sum <= ldvd) {
                sum += sum;
                count += count;
            }
            ldvd -= sum;
            res += count;
        }
        return sign * res;
    }
};


int main() {
    return 0;
}
