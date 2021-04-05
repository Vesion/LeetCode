#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Clean code!
class Solution {
public:
    string digit[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string ten[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ret = int2string(num);
        return ret.substr(1, ret.length() - 1); // trim
    }

    string int2string(int n) {
        if (n >= 1000000000) {
            return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
        } else if (n >= 1000000) {
            return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
        } else if (n >= 1000) {
            return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
        } else if (n >= 100) {
            return int2string(n / 100) + " Hundred" + int2string(n % 100);
        } else if (n >= 20) {
            return  " " + ten[n / 10] + int2string(n % 10);
        } else if (n >= 1) {
            return " " + digit[n];
        } else {
            return "";
        }
    }
};

int main() {
    Solution s;
    return 0;
}

