#include <iostream>
using namespace std;

// the famous 'Digital Root' problem
// https://en.wikipedia.org/wiki/Digital_root


// Solution 1 : trivial iterative
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num)  sum += num % 10, num /= 10; 
            num = sum;
        }
        return num;
    }
};


// Solution 2 : use formula
// for decimal (base is 10), its digital root: dr(n) = 1 + (n-1) % 9
class Solution_2 {
public:
    int addDigits(int num) {
        return 1 + (num-1)%9;
    }
};


int main() {
    return 0;
}
