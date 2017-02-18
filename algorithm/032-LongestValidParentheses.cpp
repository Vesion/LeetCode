#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Solution 1 : stack
class Solution_1 {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        stack<int> st; // record '(' index
        int start = -1; // the last dismathced ')'
        int res = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else {
                if (st.empty()) start = i;
                else {
                    st.pop();
                    if (st.empty()) res = max(res, i-start); // )...(...)
                    else res = max(res, i-st.top()); // (...(...)
                }
            }
        }
        return res;
    }
};


// Solution 2 : dp
// dp[i] means the longest parentheses ending with s[i]
//      1. when s[i] == '(', dp[i] = 0
//      2. when s[i] == ')', we need to check if s[i-dp[i-1]-1] is '(' or not
//          if it is '(', it means we find a valid pair, then dp[i] = dp[i-1] + 2, if not do nothing
//          furthermore, we also need to check if we can connect current valid pair with previous adjacent one
//          if i-dp[i-1]-2 >= 0, we connect current one with previous one
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n); 
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                int left = i-dp[i-1]-1;
                if (left >= 0 && s[left] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (left-1 >= 0) dp[i] += dp[left-1];
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.longestValidParentheses("((()))");
    return 0;
}

