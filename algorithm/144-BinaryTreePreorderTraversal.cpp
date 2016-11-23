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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* root, vector<int>& res) {
        if (root) {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }
};


// Solution 2 : iterative, stack
class Solution_2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            res.push_back(t->val);
            if (t->right) st.push(t->right);
            if (t->left) st.push(t->left);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

