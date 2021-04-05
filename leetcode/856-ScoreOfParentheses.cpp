#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// DFS
class Solution0 {
public:
    int scoreOfParentheses(string S) {
        int i = 0;
        return dfs(S, i);
    }

    int dfs(const string& s, int& i) {
        int res = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                if (s[i+1] == ')') { res += 1; i += 2; }
                else res += 2 * dfs(s, ++i);
            } else {
                ++i;
                break;
            }
        }
        return res;
    }
};


// stack
class Solution1 {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                st.push(res);
                res = 0;
            } else {
                res += st.top() + max(res, 1);
                st.pop();
            }
        }
        return res;
    }
};


// math, count level
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, l = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') l++; else l--;
            if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
        }
        return res;
    }
};


int main() {

}