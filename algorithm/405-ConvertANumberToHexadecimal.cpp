#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;


// Solution 1 : use std:sstream and std::hex
class Solution_std {
public:
    string toHex(int num) {
        stringstream ss;
        ss << hex << num;
        return ss.str();
    }
};


// Solution 2
class Solution {
public:
    string m = "0123456789abcdef";

    string toHex(int num) {
        if (num == 0) return "0";
        string result = "";
        while (num && result.size() < 8) {
            result = m[num&15] + result;
            num >>= 4;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.toHex(-1);
    return 0;
}
