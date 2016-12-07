#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Naive simulation solution is O(n^2), get TLE!
//
// A light will be toggled only during the round of its divisors.
//      e.g. Bulb 6 can only be toggled in round 1, 2, 3, 6
// As a result, bulb i is finally on, if and only if its number of divisors are odd, like bulb 1, 4, 9... And they are all perfect square numbers!
// So the rest work is find all perfect square numbers in n.
class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        for (int i = 1; i*i <= n; ++i) res++;
        return res;
        // or
        // return sqrt(n);
    }
};

int main() {
    Solution s;
    cout << s.bulbSwitch(1000000) <<endl;
    return 0;
}

