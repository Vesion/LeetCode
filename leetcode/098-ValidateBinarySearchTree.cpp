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


// Solution 1 : inorder traverse, stack
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            if (pre && cur->val <= pre->val) return false;
            pre = cur;
            cur = cur->right;
        }
        return true;
    }
};


// Solution 1.1: inorder traverse, recursion
class Solution1 {
public:
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (prev && prev->val >= root->val) return false;
        prev = root;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};


// Solution 2 : determine a node's val if is in valid range, recursively
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        return root->val > lower && root->val < upper
            && isValid(root->left, lower, root->val)
            && isValid(root->right, root->val, upper);
    }
};


int main() {
    return 0;
}
