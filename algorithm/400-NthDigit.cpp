#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long c = 9;
        long long i = 1;
        while (n - i*c > 0)  {
            n -= i*c;
            c *= 10;
            i++;
        }

        long long j = pow(10, i-1) + n / i - 1;
        long long k = n % i;
        if (k == 0) return j % 10;
        else return to_string(++j)[k-1] - '0';
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(4) << endl;;
    return 0;
}
