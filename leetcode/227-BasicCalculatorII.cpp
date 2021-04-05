#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

// top-down parse
// similar to 224-BasicCalculator but no need recursion
class Solution {
public:
    using ll = long long;
    int calculate(string s) {
        int n = s.size();
        ll num = 0;
        ll res = 0;
        int sign = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num*10 + s[i]-'0';
            } else if (s[i] == '+' || s[i] == '-') {
                res += num*sign;
                sign = s[i] == '+' ? 1 : -1;
                num = 0;
            } else if (s[i] == '*' || s[i] == '/') {
                char c = s[i++];
                while (i < n && s[i] == ' ') ++i;
                ll right = 0;
                while (i < n && (s[i] >= '0' && s[i] <= '9')) {
                    right = right*10 + s[i++]-'0';
                }
                if (c == '*') num *= right;
                else if (right == 0) return -1;
                else num /= right;
                --i;
            }
        }
        return res + num*sign;
    }
};


// stack
// why need stack? because we have to store left-hand-number for * and /
class Solution1 {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) num = num*10 + (s[i]-'0');
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n-1) { // meet +-*/ or reach last character
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    st.top() *= num;
                } else {
                    st.top() /= num;
                }
                num = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    return 0;
}

