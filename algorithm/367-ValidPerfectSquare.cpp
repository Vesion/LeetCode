#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : similar to 069-Sqrt, implement sqrt with bianry searching
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num/2;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (mid < num/mid) left = mid+1; // don't use mul in case overflow
            else right = mid-1;
        }
        return left*left == num;
    }
};


// Solution 2 : Math solution
//      A perfect square number can be wirtten as 1 + 3 + 7 + 9 + ...
//      Proof: 1 + 3 + ... + (2n-1) = (1 + 2n-1) * n / 2 = n * n
class Solution_2 {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

int main() {
    Solution_2 s;
    cout << s.isPerfectSquare(808201) <<endl;
    //cout << mySqrt(INT_MAX) << endl;
    return 0;
}
