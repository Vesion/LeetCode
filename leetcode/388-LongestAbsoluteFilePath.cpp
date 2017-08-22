#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// stack, greedy
class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.empty()) return 0;
        stack<int> st;
        int res = 0;
        int i = 0, n = input.size();
        while (i < n) {
            if (input[i] == '\n') { ++i; continue; }
            
            int level = 0;
            while (i < n && input[i] == '\t') { ++i; ++level; }
            
            int len = 0;
            while ((int)st.size() > level) st.pop();
            len = st.empty() ? 0 : st.top()+1;

            bool isfile = false;
            while (i < n && input[i] != '\n') {
                if (input[i++] == '.') isfile = true;
                ++len;
            }
            
            if (isfile) res = max(res, len);
            else st.push(len);
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") <<endl;;
    return 0;
}
