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
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (guess(mid) == 0) return mid;
            if (guess(mid) == 1) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};


int main() {
    return 0;
}
