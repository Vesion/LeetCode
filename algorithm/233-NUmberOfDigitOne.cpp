#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long r = n / i, m = n % i;
            res += (r+8)/10*i + (r%10 == 1 ? m+1 : 0);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
