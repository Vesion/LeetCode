#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

bool isOperator(string &t) {
    return (t == "+" || t == "-" || t == "*" || t == "/");
}

int op(int left, int right, string& op) {
    if (op == "+") return left + right;
    if (op == "-") return left - right;
    if (op == "*") return left * right;
    if (op == "/") return left / right;
    return 0;
}

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto & token : tokens) {
        if (!isOperator(token)) {
            s.push(stoi(token));
            continue;
        }
        int right = s.top(); s.pop();
        int left = s.top(); s.pop();
        s.push(op(left, right, token));
    }
    return s.top();
}

int main() {
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl;
    return 0;
}
