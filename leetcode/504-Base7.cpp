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
        bool sign = num > 0;
        num = abs(num);
        string res;
        while (num) {
            res = to_string(num%7) + res;
            num /= 7;
        }
        return sign ? res : "-"+res;
    }
};


int main() {
    return 0;
}
