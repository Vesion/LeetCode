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
    using ll = long long;
    bool canMeasureWater(ll x, ll y, ll z) {
        if (z == 0) return true;
        if (x*y == 0) return z == x || z == y;
        ll g = gcd(x, y);
        return (z%g == 0 && z <= x+y);
    }

    ll gcd(ll x, ll y) {
        if (y == 0) return x;
        return gcd(y, x%y);
    }
};

int main() {
    Solution s;
    cout << s.gcd(2, 12314) << endl;
    return 0;
}
