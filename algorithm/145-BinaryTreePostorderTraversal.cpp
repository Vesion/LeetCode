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

// Solution 1 : recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    void postorder(TreeNode* root, vector<int>& res) {
        if (root) {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }
};


// Solution 2 : iterative, stack
class Solution_2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        TreeNode *pre = NULL, *cur = root;
        vector<int> res;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* t = st.top();
                if (t->right && t->right != pre) {
                    cur = t->right;
                } else {
                    pre = t;
                    st.pop();
                    res.push_back(t->val);
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}

