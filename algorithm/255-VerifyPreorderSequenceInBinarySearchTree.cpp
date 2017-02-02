#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// https://discuss.leetcode.com/topic/41210/c-easy-to-understand-solution-with-thought-process-and-detailed-explanation
// if a node is in the right subtree of a root, then all nodes come after must be larger than that root

// Solution 1 : stack, O(n) time, O(n) space
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int pre = INT_MIN; // the predecessors's value of current node
        for (int& cur : preorder) {
            if (cur < pre) return false; // nodes in current's right subtree cannot be smaller than predecessor
            while (!st.empty() && cur > st.top()) { // enter right subtree
                pre = st.top();
                st.pop();
            }
            st.push(cur);
        }
        return true;
    }
};


// Solution 2 : use 'preorder' array to simulate stack, O(1) space
class Solution_2 {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        int pre = INT_MIN, i = -1;
        for (int& cur : preorder) {
            if (cur < pre) return false;
            while (i != -1 && cur > preorder[i]) {
                pre = preorder[i--];
            }
            preorder[++i] = cur;
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<int> p = {8,5,4,6,12,7,20};
    cout << s.verifyPreorder(p) << endl;
    return 0;
}
