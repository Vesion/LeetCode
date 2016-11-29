#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
using namespace std;

// Solution 1 : stringstream
class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int res = 0, left = 0, right = 0;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                res += left;
                in >> left;
                left *= (op == '+' ? 1 : -1);
            } else {
                in >> right;
                if (op == '*') left *= right;
                else left /= right;
            }
        }
        return res;
    }    
};


// Solution 2 : stack
class Solution_2 {
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
    Solution s;
    return 0;
}

