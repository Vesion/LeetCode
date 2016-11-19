#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Similar to 098-ValidateBinarySearchTree, find two invalid nodes, and swap their values
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode *e1 = NULL, *e2 = NULL;
        TreeNode *pre = NULL, *cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            if (pre && cur->val <= pre->val) {
                if (!e1) e1 = pre;
                e2 = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(e1->val, e2->val);
    }
};

int main() {
    Solution s;
    return 0;
}

