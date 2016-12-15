#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid;
        while (left <= right) {
            mid = left + (right-left)/2;
            int res = guess(mid);
            if (res == 0) break;
            if (res == 1) left = mid+1;
            else right = mid-1;
        }
        return mid;
    }
};

int main() {
    Solution s;
    cout << s.guessNumber(10) << endl;
    return 0;
}
