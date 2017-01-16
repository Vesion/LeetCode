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
        int i = 0, n = input.size();
        stack<int> st;
        int res = 0;
        while (i < n) {
            while (input[i] == '\n') ++i;

            int level = 0;
            while (i < n && input[i] == '\t') { ++level; ++i; } // count tabs as level
            while ((int)st.size() > level) st.pop(); // pop larger level directories to find its parent directory

            int len = st.empty() ? 0 : st.top()+1; // get its parent's length, +1 to count '/'
            bool isfile = false;
            while (i < n && input[i] != '\n') { // count its length
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
