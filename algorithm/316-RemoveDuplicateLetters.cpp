#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// stack, greedy
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> m(128, 0);
        vector<bool> inst(128, 0);
        for (char c : s) ++m[c];

        string st;
        for (char c : s) {
            --m[c];
            if (inst[c]) continue;
            while (!st.empty() && c <= st.back() && m[st.back()]) {
                inst[st.back()] = false;
                st.pop_back();
            }
            st.push_back(c);
            inst[c] = true;
        }
        return st;
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicateLetters("baab") << endl;
    return 0;
}

