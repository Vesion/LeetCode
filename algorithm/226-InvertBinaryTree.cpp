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

// can be solved by preorder/postorder traversal


// Solution 1 : recursive, postorder traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};


// Solution 2 : iterative, preorder traversal
class Solution_2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top(); st.pop();
            swap(t->left, t->right);
            if (t->right) st.push(t->right);
            if (t->left) st.push(t->left);
        }
        return root;
    } 
};


int main() {
    return 0;
}
