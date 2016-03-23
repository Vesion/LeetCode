#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Solution 0 : brute-force, simulate the whole process, O(n^2) time, TLE
int bulbSwitch_bf(int n) {
    if (n < 1) return 0;
    vector<bool> bulbs(n, false);
    for (int i = 1; i <= n; ++i) {
        for (int j = i-1; j < n; j += i)
            bulbs[j] = ~bulbs[j];
    }
    int result = 0;
    for (auto b : bulbs) result += b;
    return result;
}


// Solution 1 : mathematical
// A light will be toggled only during the round of its divisors.
//      e.g. Bulb 6 can only be toggled in round 1, 2, 3, 6
// As a result, bulb i is finally on, if and only if its number of divisors are odd, like bulb 1, 4, 9... And they are all perfect square numbers!
// So the rest work is find all perfect square numbers in n.
int bulbSwitch_math(int n) {
    int result = 0;
    for (int i = 1; i*i <= n; ++i) ++result;
    return result;
}

// Solution 1 v2
int bulbSwitch_math_sqrt(int n) {
    return sqrt(n);
}

int main() {
    cout << bulbSwitch_bf(10000) << endl;
    cout << bulbSwitch_math(10000) << endl;
    cout << bulbSwitch_math_sqrt(10000) << endl;
    return 0;
}
