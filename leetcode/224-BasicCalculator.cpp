#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// Solution 1 : top-down parser, recursive descent
class Solution {
public:
    using ll = long long;
    int calculate(string s) {
        int i = 0;
        return parse(s, i);
    }

    ll parse(const string& s, int& i) {
        ll num = 0, sign = 1;
        ll res = 0;
        for (; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num*10 + s[i]-'0';
            } else if (s[i] == '(') {
                res += sign * parse(s, ++i);
            } else if (s[i] == ')') {
                break;
            } else if (s[i] == '+' || s[i] == '-') {
                res += num*sign;
                sign = s[i] == '+' ? 1 : -1;
                num = 0;
            }
        }
        return res + num*sign;
    }
};


// Solution 2 : use stack manually
class Solution_2 {
public:
    int calculate(string s) {
        int res = 0, sign = 1, i = 0;
        stack<int> st;
        while (i < (int)s.size()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < (int)s.size() && isdigit(s[i])) num = num*10 + s[i++]-'0';
                res += num*sign;
            } else if (s[i] == '+') {
                sign = 1; ++i;
            } else if (s[i] == '-') {
                sign = -1; ++i;
            } else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0, sign = 1;
                ++i;
            } else if (s[i] == ')') {
                int outer_sign = st.top(); st.pop();
                int outer_res = st.top(); st.pop();
                res = outer_res + res*outer_sign;
                ++i;
            } else ++i;
        }
        return res;
    }
};


int main() {
    Solution_2 s;
    cout << s.calculate("1+1") << endl;
    cout << s.calculate("2-1+2") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << s.calculate("1-(5)") << endl;
    return 0;
}

