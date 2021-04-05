#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// Simpler variant of 301-RemoveInvalidParentheses
// because only need to return one of the results
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        deque<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push_back(i);
            else if (s[i] == ')') {
                if (st.empty()) s[i] = '*';
                else st.pop_back();
            }
        }
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (!st.empty() && st.front() == i) {
                st.pop_front();
                continue;
            }
            if (s[i] == '*') continue;
            res += s[i];
        }
        return res;
    }
};

int main() {

}