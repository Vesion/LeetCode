#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : iterative
class Solution {
public:
    int getSum(int a, int b) {
        while (b) { // repeat until no carry
            int carry = a & b; // get carry of a+b
            a = a ^ b; // get sum of a+b without thinking of carry
            b = carry << 1; // shift carry for next turn
        }
        return a;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a^b, (a&b)<<1);    
    }
};


int main() {
    return 0;
}
