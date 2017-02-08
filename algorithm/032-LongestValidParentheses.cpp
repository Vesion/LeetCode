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
                    if (st.empty()) res = max(res, i-start); // )(...)
                    else res = max(res, i-st.top()); // ((...)
                }
            }
        }
        return res;
    }
};


// Solution 2 : dp
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n, 0); // dp[i] means the longest length when ending with s[i]
        int lefts = 0; // unmatching '('s
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') ++lefts;
            else {
                if (lefts > 0) {
                    dp[i] = dp[i-1] + 2; // match a pair
                    if (i-dp[i] > 0) dp[i] += dp[i-dp[i]]; // add previous pairs
                    --lefts;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.longestValidParentheses("((()))");
    return 0;
}

