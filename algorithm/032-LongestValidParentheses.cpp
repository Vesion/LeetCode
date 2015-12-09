#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <iterator>
using namespace std;

// brute-force, TLE
bool isValid(string s) {
    int len = s.length();
    if (len == 0 || (len & 1))
        return false;
    stack<char> st;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ')') {
            if (st.empty()) 
                return false;
            st.pop();
        } else 
            st.push('(');
    }
    return st.empty();
}

int longestValidParentheses_slow(string s) {
    if (s.length() < 2) return 0;
    int result = -1;
    for (auto i = begin(s); i != prev(end(s)); ++i) {
        auto j = prev(end(s));
        int t;
        for (; j > i; --j) {
            if (isValid(string(i, next(j)))) {
                t = distance(i, j) + 1;
                break;
            }
        }
        result = max(result, t);
    }
    return result;
}

// stack, common solution, O(n), O(n)
int longestValidParentheses_stack(string s) {
    int len = s.length();
    if (len < 2) return 0;
    stack<int> lefts; // push non-matching '('
    int last = -1; // the position of the last ')'
    int result = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ')') {
            if (lefts.empty())
                last = i;
            else {
                lefts.pop();
                if (lefts.empty())
                    result = max(result, i - last);
                else
                    result = max(result, i - lefts.top());
            }
        } else
            lefts.push(i);
    }
    return result;
}

// DP, not very easy to get, O(N), O(N)
int longestValidParentheses_dp(string s) {
    int len = s.length();
    if (len < 2) return 0;
    vector<int> f(len, 0); // status array
    int result = 0;
    for (int i = len-2; i >= 0; --i) {
        // status transition function, ( ............... )
        //                             i <---f[i+1]---> match
        int match = i + f[i+1] + 1;
        if (s[i] == '(' && match < len && s[match] == ')') {
            f[i] = f[i+1] + 2;
            if (match + 1 < len) // a point difficult to see, ( ...... )()...
                f[i] += f[match+1];
        }
        result = max(result, f[i]);
    }
    return result;
}

int main() {
    string s("(((())))()()()()");
    cout << longestValidParentheses_dp(s) << endl;
    return 0;
}
