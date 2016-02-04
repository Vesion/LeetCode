#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x < 2)
        return x;
    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x / mid > mid) { // do not use mid * mid < x, in case of overflow
            left = mid + 1;
        } else if (x / mid < mid) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return right;
}

int main() {
    cout << mySqrt(6) << endl;
    return 0;
}
