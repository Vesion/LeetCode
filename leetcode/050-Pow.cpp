#include <iostream>
using namespace std;

// recursive, top-down
class Solution_1 {
public:
    double myPow_topdown(double x, int n) {
        if (n == 0)
            return 1;
        if (n < 0) {
            if (n == INT_MIN) // for corner case pow(1, INT_MIN)
                return myPow_topdown(x, n/2) * myPow_topdown(x, n/2);
            return 1 / myPow_topdown(x, -n);
        }
        if (n == 1)
            return x;
        if (n & 1) return myPow_topdown(x, n-1) * x;
        else return myPow_topdown(x*x, n/2);
    }
};


// bottom up
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == INT_MIN) return myPow(x, n/2) * myPow(x, n/2);
            else return 1.0 / myPow(x, -n);
        }
        double res = 1;
        while (n) {
            if (n&1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.myPow(-1, INT_MIN);
    return 0;
}
