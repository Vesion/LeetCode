#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// top-down parser
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        int n = s.size();
        return eval(s, i, n);
    }

    int eval(string& s, int& i, int n) {
        int res = 0;
        int sign = 1;
        while (i < n) {
            if (isdigit(s[i])) {
                int right = 0;
                while (i < n && isdigit(s[i])) {
                    right = right*10 + (s[i++]-'0');
                }
                res += sign * right;
                --i;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '(') {
                res += sign * eval(s, ++i, n);
            }
            else if (s[i] == ')') {
                break;
            }
            ++i;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.calculate("1+1") << endl;
    cout << s.calculate("2-1+2") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}

