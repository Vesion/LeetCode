#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// Simulate, O(n) space
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; j < n; ) {
            if (st.empty() || st.top() != popped[j]) {
                if (i == n) return false;
                st.push(pushed[i++]);
            } else {
                st.pop();
                ++j;
            }
        }
        return true;
    }
};


// Consider `pushed` as the stack, O(1) space1
class Solution1 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        for (int st = -1, i = 0, j = 0; j < popped.size(); ) {
            if (st == -1 || pushed[st] != popped[j]) {
                if (i == pushed.size()) return false;
                pushed[++st] = pushed[i++];
            } else {
                --st;
                ++j;
            }
        }
        return true;
    }
};


int main() {
    return 0;
}
