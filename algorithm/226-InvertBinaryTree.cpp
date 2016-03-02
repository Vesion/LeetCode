#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

// similiar to prevorder/inorder/postorder traversal

// Solution 1 : recursive, here we use preorder
TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    // swap
    swap(root->left, root->right);
    // recursive
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


// Solution 2 : iterative
TreeNode* invertTree_it(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        auto node = s.top();
        s.pop();
        if (node) {
            s.push(node->left);
            s.push(node->right);
            swap(node->left, node->right);
        }
    }
    return root;
}

int main() {
    return 0;
}
