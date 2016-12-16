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
        int res = 0;
        int i = 0, n = input.size();
        stack<int> st;
        while (i < n) {
            while (input[i] == '\n') ++i;

            int level = 0;
            while (i < n && input[i] == '\t') { // count tabs as its level
                ++level;
                ++i;
            }

            int j = i;
            bool isfile = false;
            while (j < n && input[j] != '\n') { // count its length
                if (input[j] == '.') isfile = true;
                ++j;
            }
            int len = j-i;

            while ((int)st.size() > level) st.pop(); // find its parent directory
            int parentLen = st.empty() ? 0 : st.top();
            if (isfile) res = max(res, len + parentLen);
            else st.push(parentLen+len+1);
            i = j;
        }
        return res;
    }  
};


int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") <<endl;;
    return 0;
}
