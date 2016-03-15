#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* appendNode(TreeNode* root, int x) {
    if (!root)
        root = new TreeNode(x);
    else {
        if (root->val > x) root->left = appendNode(root->left, x);
        else root->right = appendNode(root->right, x);
    }
    return root;
}

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}


// Use the property of BST, if root is a ancestor of p and q, their values must both be larger or smaller than root's value.
// So loop until it does not meet the condition above.
// This walks straight from the root to the LCA, not looking at the rest of the tree, so it's pretty much as fast as it gets.

// Solution 1 : iterative
TreeNode* lowestCommonAncestor_it(TreeNode* root, TreeNode* p, TreeNode* q) {
    while ((root->val - p->val) * (root->val - q->val) > 0)
        root = p->val > root->val ? root->right : root->left;
    return root;
}

// Solution 2 : recursive
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root = appendNode(root, 2);
    root = appendNode(root, 0);
    root = appendNode(root, 4);
    root = appendNode(root, 3);
    root = appendNode(root, 5);
    root = appendNode(root, 8);
    root = appendNode(root, 7);
    root = appendNode(root, 9);
    printInorder(root);
    cout << endl;

    cout << lowestCommonAncestor(root, root->left->left, root->right->right)->val;

    deleteTree(root);
    return 0;
}
