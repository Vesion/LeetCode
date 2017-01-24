#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long num = 1, c = 9, d = 1;
        while (n > c) {
            n -= c;
            num *= 10;
            ++d;
            c = 9*num*d;
        }
        long long k = n/d, r = n%d;
        num += k-1;
        if (r == 0) return num%10;
        else return to_string(++num)[r-1]-'0';
    }
};


int main() {
    Solution s;
    cout << s.findNthDigit(1000) << endl;
    cout << s.findNthDigit(2886) << endl;
    cout << s.findNthDigit(1000000) << endl;
    return 0;
}

