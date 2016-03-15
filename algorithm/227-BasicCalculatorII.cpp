#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Solution 1 : trivial one pass
bool isDigit(char c) { return c >= '0' && c <= '9'; }
bool isOp1(char c) { return c == '+' || c == '-'; }
bool isOp2(char c) { return c == '*' || c == '/'; }

int calculate_trivial(string s) {
    int n = s.size();
    if (n == 0) return 0;
    int result = 0, sign = 1, num = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;
        if (isDigit(s[i])) num = num * 10 + s[i]-'0';
        else if (isOp1(s[i])) { // '+' '-'
            result += sign * num;
            sign = s[i] == '+' ? 1 : -1;
            num = 0;
        }
        else if (isOp2(s[i])) { // '*' '/'
            int left = num, right = 0;
            int op = s[i] == '*' ? 1 : -1;
            for (++i; i < n && !isOp1(s[i]); ++i) {
                if (s[i] == ' ') continue;
                if (isDigit(s[i])) right = right * 10 + s[i]-'0';
                else {
                    left = op == 1 ? left * right : left / right;
                    op = s[i] == '*' ? 1 : -1;
                    right = 0;
                }
            }
            if (right) left = op == 1 ? left * right : left / right;
            --i;
            num = left;
        }
    }
    result += sign * num;
    return result;
}


// Solution 2 : skillful and well played
// learn to use istringstream
int calculate_ss(string s) {
    istringstream in('+' + s + '+');
    int result = 0, left = 0, right = 0;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            result += left;
            in >> left;
            left *= 44 - op;
        } else {
            in >> right;
            if (op == '*') left *= right;
            else left /= right;
        }
    }
    return result;
}


int main() {
    //cout << calculate_trivial("3+5 / 2") << endl;
    cout << calculate_ss("13+51 / 21") << endl;
    return 0;
}
