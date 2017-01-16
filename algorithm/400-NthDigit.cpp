#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1, d = 1;
        long long count = 9;
        while (n > count) {
            n -= count;
            start *= 10;
            ++d;
            count = 9 * start * d;
        }

        int k = n / d;
        int r = n % d;
        int res = start + k - 1;
        if (r == 0) return res%10;
        else return to_string(++res)[r-1]-'0';
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(1000000000) <<endl;
    return 0;
}

