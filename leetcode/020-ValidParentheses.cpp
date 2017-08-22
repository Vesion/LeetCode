#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                if (s[i] == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};


int main() {
    return 0;
}

