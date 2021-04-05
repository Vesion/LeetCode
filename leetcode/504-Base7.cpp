#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// similar to 405-ConvertANumberToHexadecimal
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool negative = num < 0;
        num = abs(num);
        string res;
        while (num) {
            res += num % 7 + '0';
            num /= 7;
        }
        reverse(res.begin(), res.end());
        if (negative) res = "-" + res;
        return res;
    }
};


int main() {
    return 0;
}
