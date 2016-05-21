#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Similar to 326-PowerOfThree

// Solution 1 : recursive
bool isPowerOfFour_re(int num) {
    return (num > 0 && (num == 1 || (num % 4 == 0 && isPowerOfFour_re(num/4))));
}

// Solution 2 : iterative
bool isPowerOfFour_it(int num) {
    if (num > 1)
        while (num % 4 == 0) num /= 4;
    return num == 1;
}

// Solution 3 : table checking
bool isPowerOfFour_table(int num) {
    vector<int> pow4;
    for (int i = 1; i > 0 && i <= INT_MAX; i *= 4) pow4.push_back(i);
    return binary_search(pow4.begin(), pow4.end(), num);
}


// Similar to 231-PowerOfTwo

// Solution 5 : bit manipulation with mod 3
// Proof# : 4^x-1=(2^x-1)(2^x+1). And 2^x mod 3 is not 0. So either 2^x-1 or 2^x +1 must be 0.
bool isPowerOfFour_mod(int num) {
    return num > 0 && !(num & (num-1)) && !((num-1) % 3);
}

// Solution 6 : bit manipulation with and 
// 0x55555555 is to get rid of those power of 2 but not power of 4, so that the single 1 bit always appears at the odd position 
bool isPowerOfFour_and(int num) {
    return num > 0 && !(num & (num-1)) && (num & 0x55555555);
}



int main() {
    cout << isPowerOfFour_re(16) << endl;
    cout << isPowerOfFour_it(12) << endl;
    cout << isPowerOfFour_table(16) << endl;
    cout << isPowerOfFour_mod(16) << endl;
    cout << isPowerOfFour_and(16) << endl;
    return 0;
}
