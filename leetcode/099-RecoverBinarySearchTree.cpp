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

// Solution 1 : inorder traversal with stack, O(logn) space
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        TreeNode *cur = root, *pre = NULL;
        TreeNode *e1 = NULL, *e2 = NULL;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                if (pre && cur->val < pre->val) {
                    if (!e1) e1 = pre; // be careful with the [0, 1] corner case
                    e2 = cur;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        swap(e1->val, e2->val);
    }
};


// Solution 2 : Morris traversal, O(1) space


int main() {
    return 0;
}

