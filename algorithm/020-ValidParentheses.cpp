#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    if (s.size() == 0)
        return true;
    stack<char> ops;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            ops.push(s[i]);
        }
        else if (s[i] == ')') {
            if (!ops.empty() && ops.top() == '(')
                ops.pop();
            else
                return false;
        }
        else if (s[i] == ']') {
            if (!ops.empty() && ops.top() == '[')
                ops.pop();
            else
                return false;
        }
        else if (s[i] == '}') {
            if (!ops.empty() && ops.top() == '{')
                ops.pop();
            else
                return false;
        }
    }
    if (!ops.empty())
        return false;
    return true;
}

int main() {
    string s = "{{{{}}";
    cout << isValid(s) << endl;
    system("pause");
    return 0;
}