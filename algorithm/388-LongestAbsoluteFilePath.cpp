#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

vector<string> split(string& s, char f) {
    vector<string> r;
    s.push_back(f);
    unsigned long i = 0, j = s.find(f, 0);
    while (j != string::npos) {
        r.push_back(s.substr(i, j-i));
        i = j+1;
        j = s.find(f, i);
    }
    return r;
}

// Solution 1.1 : stack
class Solution_st {
public:
    int lengthLongestPath(string input) {
        int result = 0;

        stack<int> st;
        st.push(0);
        auto ss = split(input, '\n');
        for (auto& s : ss) {
            auto level = s.find_first_not_of('\t'); // level start from 0
            while (level+1 < st.size()) st.pop(); // find its parent
            int len = st.top() + 1 + s.size() - level; // 'parent/s'
            st.push(len);
            if (s.find('.') != string::npos) result = max(result, len-1); // remove the first '/'
        }
        return result;
    }
};


// Solution 1.2 : use vector as stack
class Solution {
public:
    int lengthLongestPath(string input) {
        int result = 0;
        auto ss = split(input, '\n');
        vector<int> lens(ss.size());
        for (auto& s : ss) {
            auto level = s.find_first_not_of('\t');
            int len = lens[level] + 1 + s.size() - level;
            lens[level+1] = len;
            if (s.find('.') != string::npos) result = max(result, len-1);
        }
        return result;
    }
};


int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") <<endl;;
    return 0;
}
