#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x = INT_MAX;
        while (x >= 40) x = 7 * (rand7()-1) + rand7()-1;  // [0, 39]
        return x % 10 + 1;
    }
};

int main() {
}
