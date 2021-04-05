#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        constexpr char m[] = "0123456789abcdef";
        string res;
        while (num && res.size() < 8) {  // why < 8? consider num is -1
            res += m[num&0xf];  // num & 0xf == num % 16
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.toHex(-1) << endl;
    return 0;
}

