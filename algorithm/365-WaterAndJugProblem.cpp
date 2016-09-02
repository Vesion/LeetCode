#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// The classical "Water and Jug" problem.
// The Math knowledge behind it is Bézout's identity:
//      If d is the gcd of two integers a and b, then d must equal to ax + by, x and y are integers. 
//      And d is the smallest integer which can be written as that.
//      So, if z is a multiple of gcd(x, y), it's true, becase z = ax + by,
//          if a (or b) is positive, it means filling x (or y) jug up a times,
//          if a (or b) is negative, it means emptying x (or y) jug down b times.

class Solution {
public:
    int gcd(int x, int y) {
        if (x < y) return gcd(y, x);
        if (y == 0) return x;
        return gcd(y, x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z > x+y) return false;
        if (x == 0) return z == 0 || z == y;
        if (y == 0) return z ==0 || z == x;
        return z % gcd(x, y) == 0;
    }
};

int main() {
    Solution s;
    cout << s.gcd(2, 12314) << endl;
    return 0;
}
