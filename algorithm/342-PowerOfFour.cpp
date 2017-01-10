#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : bitmap
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num&(num-1)) == 0) && (num&0x55555555);
    }
};


// Solution 2 : math, num-1 must be divided by 3
class Solution_2 {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if (num & (num-1)) return false;
        return (num-1)%3 == 0;
    }
};



int main() {
    Solution_2 s;
    cout << s.isPowerOfFour(64) <<endl;
    return 0;
}

