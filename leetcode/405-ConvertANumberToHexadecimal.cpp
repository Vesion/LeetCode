#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string m = "0123456789abcdef";
        string res;
        while (num && res.size() < 8) {
            res = m[num&0xf] + res; // num & 0xf equals to (unsigned)num % 16
            num >>= 4;
        }
        return res;
    }   
};

int main() {
    Solution s;
    cout << s.toHex(-1) << endl;
    return 0;
}

