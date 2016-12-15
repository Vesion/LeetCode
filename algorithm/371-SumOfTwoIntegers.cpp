#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : recursive
class Solution {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a^b, (a&b)<<1);    
    }
};


// Solution 2 : iterative
class Solution_2 {
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


int main() {
    Solution s;
    cout << s.getSum(99, 99) <<endl;
    return 0;
}

