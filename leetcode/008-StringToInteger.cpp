#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int i = 0, sign = 1;
        while (s[i] == ' ') ++i;
        if (s[i] == '+') ++i;
        else if (s[i] == '-') sign = -1, ++i;

        int res = 0;
        for (; i < n; ++i) {
            if (s[i] < '0' || s[i] > '9') break;
            if (res > INT_MAX/10 ||
                (res == INT_MAX/10 && s[i]-'0' > INT_MAX%10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res*10 + (s[i]-'0');
        }
        return res*sign;
    }
};


int main() {
    return 0;
}
