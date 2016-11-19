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


// Solution 1 : determine its inorder traversal if is a increasing sequence
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


// Solution 2 : determine a node's val if is in valid range, recursively
class Solution_2 {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MAX, LONG_MIN);
    }

    bool dfs(TreeNode* root, long long upper, long long lower) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return dfs(root->left, root->val, lower) && dfs(root->right, upper, root->val);
    }
};


int main() {
    Solution s;
    return 0;
}

