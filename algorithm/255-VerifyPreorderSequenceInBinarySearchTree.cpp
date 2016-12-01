#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;


// Solution 0 : check recursively according BST definition, TLE
class Solution_0 {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verify(preorder, 0, preorder.size());
    }
    
    bool verify(vector<int>& preorder, int start, int end) {
        if (start+1 >= end) return true;
        int root = preorder[start];
        int right = start+1;
        while (right < end) {
            if (preorder[right] > root) {
                for (int i = right; i < end; ++i) if (preorder[i] < root) return false;
                break;
            }
            ++right;
        }
        return verify(preorder, start+1, right) && verify(preorder, right, end);
    }
};


// Solution 1 : stack
// https://discuss.leetcode.com/topic/41210/c-easy-to-understand-solution-with-thought-process-and-detailed-explanation
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int pre = INT_MIN; // the predecessors's value of current node
        for (int cur : preorder) {
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


int main() {
    Solution s;
    vector<int> p = {8,5,4,6,12,7,20};
    cout << s.verifyPreorder(p) << endl;
    return 0;
}
