#include <iostream>
using namespace std;

// Same with 'The Beauty of Programming' Problem 2.4


// refer to https://leetcode.com/discuss/44281/4-lines-o-log-n-c-java-python
int countDigitOne(int n) {
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10)
        ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
    return ones;
}

// a more clear explanation
// https://leetcode.com/discuss/64962/java-python-one-pass-solution-easy-to-understand
int countDigitOne_2(int n) {
    if (n <= 0) return 0;
    int q = n, x = 1;
    int result = 0;
    do {
        int digit = q % 10;
        q /= 10;
        result += q * x;
        if (digit == 1) result += n % x + 1;
        else if (digit > 1) result += x;
        x *= 10;
    } while (q);
    return result;
}

int main() {
    cout << countDigitOne(10000000) << endl;
    cout << countDigitOne_2(10000000) << endl;
    return 0;
}
