#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
using namespace std;

// Solution 1 : stack
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return true;
        istringstream in(preorder);
        stack<string> st;
        string val;
        while (getline(in, val, ',')) {
            if (val == "#") {
                while (!st.empty() && st.top() == "#") {
                    st.pop();
                    if (st.empty()) return false;
                    st.pop();
                }
            }
            st.push(val);
        }
        return st.size() == 1 && st.top() == "#";
    }
};


// Solution 2 : indegrees and outdegrees
//      all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
//      all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
class Solution_2 {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;
        istringstream in(preorder);
        int diff = 1;
        string val;
        while (getline(in, val, ',')) {
            if (--diff < 0) return false;
            if (val != "#") diff += 2;
        }
        return diff == 0;
    }
};

int main() {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("1,2,#,3,#,#,4,#,#") << endl;
    cout << s.isValidSerialization("#") << endl;
    return 0;
}

