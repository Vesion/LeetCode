#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

// very classical expression evaluation problem, stack or recursion


bool isDigit(int c) { return c >= '0' && c <= '9'; }


// Solution 1 : use one stack, tokens
// put all numbers and ops into stack, until meet a ')', then pop them out and evaluate them until meet a '('
int eval(stack<int>& exp) {
    int result = 0;
    int right;
    int cnt = 1; // distinguish number and ops '(', '+', '-'
    while (!exp.empty()) {
        int token = exp.top(); exp.pop();
        if (cnt & 1) right = token;
        else {
            if (token == '+') result += right;
            else if (token == '-') result -= right;
            else if (token == '(') break;
        }
        ++cnt;
    }
    result += right;
    return result;
}

int calculate_one(string s) {
    s = "(" + s + ")";
    stack<int> exp;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;
        if (isDigit(s[i])) { // '0'-'9'
            int num = 0;
            while (isDigit(s[i])) num = num * 10 + s[i++]-'0';
            exp.push(num);
            --i;
        }
        else if (s[i] == ')') {
            exp.push(eval(exp));
        }
        else exp.push(s[i]); // '+' '-' '('
    }
    return exp.top();
}


// Solution 2 : use two stacks, nums and ops 
int calculate_two(string s) {
    stack<int> nums, ops;
    int num = 0, result = 0, sign = 1;
    for (auto & c : s) {
        if (isDigit(c)) num = num * 10 + c-'0';
        else {
            result += num * sign;
            num = 0;
            if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '(') {
                nums.push(result); ops.push(sign);
                result = 0; sign = 1;
            }
            else if (c == ')') {
                int op = ops.top(); ops.pop();
                result = op * result + nums.top(); nums.pop();
            }
        }
    }
    result += sign * num;
    return result;
}


// Solution 3 : recursive
int eval(string& s, int& i) {
    int result = 0, sign = 1;
    int n = s.size();
    while (i < n && s[i] != ')') {
        if (s[i] == ' ') { ++i; continue; }
        if (s[i] == '+') { sign = 1; ++i; }
        else if (s[i] == '-') { sign = -1; ++i; }
        else if (s[i] == '(') {
            ++i;
            result += sign * eval(s, i);
            sign = 1;
        }
        else {
            int num = 0;
            while (i < n && isDigit(s[i])) num = num * 10 + s[i++]-'0';
            result += num * sign;
        }
    }
    ++i;
    return result;
}

int calculate_re(string s) {
    int pos = 0;
    return eval(s, pos);
}


int main() {
    cout << calculate_one("1+(1-2)") << endl;
    cout << calculate_two("1+(1-2)") << endl;
    cout << calculate_re("1+(1-2)") << endl;
    return 0;
}
