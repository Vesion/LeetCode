#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1, c = 9, d = 1;
        while (n > c) {
            n -= c;
            start *= 10;
            ++d;
            c = 9 * start * d;
        }
        long long r = n/d, m = n%d;
        start += r-1;
        if (m == 0) return start%10;
        else return to_string(++start)[m-1]-'0';
    }
};


int main() {
    Solution s;
    cout << s.findNthDigit(1000) << endl;
    cout << s.findNthDigit(2886) << endl;
    cout << s.findNthDigit(1000000) << endl;
    return 0;
}

