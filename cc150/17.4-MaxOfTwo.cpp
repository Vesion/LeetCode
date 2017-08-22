#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Max of two intergers, Page 311
// Given two intergers a and b, return the max one of them, cannot use if-else statements or comparison operators.
// Idea:
//      1. Check the difference of a-b is positive or negative
//      2. But we cannot use if-else, so we check the MSB is 1 or 0
//      3. If positive we return a, otherwise return b
//          if a-b > 0, p = 1, q = 0
//          else p = 0, q = 1
//          return p*a + q*b
//      4. But hold on! What if a-b overflow?
//          If and only if a and b are in different sign, a-b will overflow
//         so we have to check this condition using the same method above

class Solution {
public:
    int getMaxOfTwo(int a, int b) {
        int sa = sign(a);
        int sb = sign(b);
        int sc = sign(a-b);

        int s = sa ^ sb;
        int t = flip(s);
        int p = s*sa + t*sc; // if a and b have different sign, we use sign of a, otherwise we use sign of a-b
        int q = flip(p);
        return p*a + q*b;
    }

    // if a is positive return 1, otherwise return 0
    int sign(int a) {
        return flip((a >> 31) & 1);
    }

    int flip(int a) {
        return a ^ 1;
    }
};


int main() {
    Solution s;    
    cout << s.getMaxOfTwo(1, 2) << endl;
    cout << s.getMaxOfTwo(2, -1) << endl;
    cout << s.getMaxOfTwo(INT_MAX, INT_MIN) << endl;
    cout << s.getMaxOfTwo(INT_MIN, INT_MAX) << endl;
    return 0;
}
