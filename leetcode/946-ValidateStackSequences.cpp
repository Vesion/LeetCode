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
        stack<int> s;
        int i = 0, j = 0;
        while (j < popped.size()) {
            if (s.empty() || s.top() != popped[j]) {
                if (i == pushed.size()) return false;
                s.push(pushed[i++]);
            }
            else {
                s.pop();
                ++j;
            }
        }
        return s.empty();
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
