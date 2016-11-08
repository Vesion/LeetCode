#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int n = str.size();

        int i = 0;
        int sign = 1;
        while (str[i] == ' ') ++i;
        if (str[i] == '+') { sign = 1; ++i; }
        else if (str[i] == '-') { sign = -1; ++i; }

        int res = 0;
        for (; i < n; ++i) {
            if (str[i] < '0' || str[i] > '9') break;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && str[i]-'0' > INT_MAX%10))
                return sign == 1 ? INT_MAX : INT_MIN;
            res = res*10 + str[i]-'0';
        }
        return res*sign;
    }
};

int main() {
    Solution s;
    return 0;
}

