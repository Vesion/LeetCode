#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& t : tokens) {
            if (isalnum(t.back())) st.push(stoi(t)); // use back() in case of like "-4"
            else {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                int result;
                if (t == "+") result = left + right;
                else if (t == "-") result = left - right;
                else if (t == "*") result = left * right;
                else if (t == "/") result = left / right;
                st.push(result);
            }
        }
        return st.empty() ? 0 : st.top();
    }
};


int main() {
    return 0;
}

