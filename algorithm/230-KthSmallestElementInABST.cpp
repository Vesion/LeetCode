#include <iostream>
#include <stack>
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
        if (x <= root->val) root->left = appendNode(root->left, x);
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

// Solution 1 : inorder traversal, iterative with stack
int kthSmallest_inorder(TreeNode* root, int k) {
    stack<TreeNode*> s;
    TreeNode* it = root;
    int result;
    while (it || !s.empty()) {
        if (it) s.push(it), it = it->left;
        else {
            it = s.top(); s.pop();
            result = it->val;
            it = it->right;
            if (!--k) break;
        }
    }
    return result;
}


// Solution 1 v2 : inorder traversal, recursive
// we do not implement here


// Solution 2 : binary search, preferable
// Here for concise code, we do not use a table to store number of each subtree's nodes, so 'countNodes' is called in recursion, costing large time and doing repetitive work.
// So if we could modify the BST node's structure, we should add a field 'number of nodes' into the structure.
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int kthSmallest(TreeNode* root, int k) {
    int left = countNodes(root->left);
    if (k <= left) return kthSmallest(root->left, k);
    if (k > left+1) return kthSmallest(root->right, k-1-left);
    return root->val; // k == left+1
}

int main() {
    TreeNode* root = NULL;
    root = appendNode(root, 6);
    root = appendNode(root, 4);
    root = appendNode(root, 3);
    root = appendNode(root, 5);
    root = appendNode(root, 8);
    root = appendNode(root, 7);
    root = appendNode(root, 9);
    printInorder(root);
    cout << endl;

    cout << kthSmallest_inorder(root, 4) << endl;
    cout << kthSmallest(root, 4) << endl;

    deleteTree(root);
    return 0;
}
