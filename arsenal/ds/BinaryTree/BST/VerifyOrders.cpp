#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Given an array of unique numbers, verify if it is the correct inorder/preorder/postorder traversal sequence of a BST.


// Version 1 : verify inorder
// This is the simplest, just check if it is monotonically increasing
bool verifyInorder(vector<int>& nums) {
    for (int i = 1; i < (int)nums.size(); ++i) {
        if (nums[i] < nums[i-1]) return false;
    }
    return true;
}


// Version 2 : verify preorder
// stack, O(n) time, O(n) space
bool verifyPreorder(vector<int>& nums) {
    int pre = INT_MIN;
    stack<int> st;
    for (int& num : nums) {
        if (num < pre) return false;
        while (!st.empty() && num > st.top()) {
            pre = st.top();
            st.pop();
        }
        st.push(num);
    }
    return true;
}


// Version 3 : verify postorder
// similar to Version 2, just scan from back to front
// because preorder is root-left-right, postorder is left-right-root
// reversed postorder is root-right-left, it's very similar to preorder
bool verifyPostorder(vector<int>& nums) {
    if (nums.empty()) return true;
    int pre = INT_MAX;
    stack<int> st;
    for (int i = nums.size()-1; i >= 0; --i) {
        if (nums[i] > pre) return false;
        while (!st.empty() && nums[i] < st.top()) {
            pre = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return true;
}


int main() {
    vector<int> postorder = {2,4,5,3,7,8,9,6};
    cout << verifyPostorder(postorder) << endl;
    return 0;
}
