#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// formula : count = [n/5] + [n/(5^2)] + [n/(n^3)] + ...
// 1...n中，每个5的倍数提供一个5，每个5^2的倍数在之前的基础上再额外提供一个5，每个5^3的倍数再额外提供一个5....

class Solution {
public:
    long long trailingZeros(long long n) {
        long long result = 0;
        while (n) {
            result += n/5;
            n /= 5;
        }
        return result;
    } 
};

int main() {
    Solution s;
    cout << s.trailingZeros(11) << endl;
    return 0;
}
