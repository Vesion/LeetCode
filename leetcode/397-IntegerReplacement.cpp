#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// bitmap
// eliminate 1 as soon as possible, so when:
//      n is even, n /= 2 (right shift)
//      n is odd, if the last two significant bits are
//          01, n -= 1
//          10, n += 1
class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long long ln = n;
        while (ln != 1) {
            if (ln&1) {
                if ((ln>>1)&1 && ln != 3) ++ln;
                else --ln;
            } else ln /= 2;
            ++res;
        }
        return res;
    }
};


int main() {
    return 0;
}
