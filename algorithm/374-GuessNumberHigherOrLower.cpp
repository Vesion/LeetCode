#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
const int target = 6;
int guess(int num) {
    if (num < target) return 1;
    if (num > target) return -1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (guess(mid) == 0) return mid;
            if (guess(mid) == -1) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.guessNumber(10) << endl;
    return 0;
}
