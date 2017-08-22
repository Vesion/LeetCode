#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        int n = str.size();
        if (n == 0) return 0;

        int i = 0;
        int sign = 1;
        while (str[i] == ' ') ++i;
        if (str[i] == '+') { sign = 1; ++i; }
        else if (str[i] == '-') { sign = -1; ++i; }
        
        int result = 0;
        for (; i < n; ++i) {
            if (str[i] < '0' || str[i] > '9') break;
            if (result > INT_MAX/10 || (result == INT_MAX/10 && str[i]-'0' > INT_MAX%10))
                return sign == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + str[i] - '0';
        }
        return result * sign;
    }
};

int main() {
    Solution s;
    cout << s.atoi("123123") << endl;
    return 0;
}
