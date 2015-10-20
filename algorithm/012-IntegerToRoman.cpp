#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    const int radix[]     = {1000, 900, 500, 400,  100, 90,   50,  40,   10,   9,    5,   4,    1};
    const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result;
    for (int i = 0; num > 0; ++i) {
        int n = num / radix[i];
        num %= radix[i];
        for (; n > 0; --n)
            result += symbol[i];
    }
    return result;
}

int main() {
    cout << intToRoman(3999);
    return 0;
}
