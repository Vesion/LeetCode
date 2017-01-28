#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Solution 1 : top-down parser, recursive descent
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parse(s, i);
    }
    
    int parse(string& s, int& i) {
        int res = 0, sign = 1;
        while (i < (int)s.size()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < (int)s.size() && isdigit(s[i])) num = num*10 + s[i++]-'0';
                res += sign * num;
            } else if (s[i] == '+') {
                sign = 1; ++i;
            } else if (s[i] == '-') {
                sign = -1; ++i;
            } else if (s[i] == '(') {
                res += sign * parse(s, ++i);
            } else if (s[i] == ')') {
                ++i; break;
            } else ++i;
        }
        return res;
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

