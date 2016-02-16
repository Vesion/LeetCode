#include <iostream>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

// Solution 1 : Min-Max range
// we use the min-val and max-val to record the range scope of the root-left-sub-tree and root-right-sub-tree
// use long in case of overflow
bool isValid(TreeNode* node, long leftMin, long rightMax) {
    if (!node) return true;
    return ((node->val > leftMin && node->val < rightMax)
            && isValid(node->left, leftMin, node->val) 
            && isValid(node->right, node->val, rightMax));
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}


// Solution 2 : inorder traversal
// refer to https://leetcode.com/discuss/81672/recommend-beginners-implementation-detailed-explaination
// do not implement here

int main() {
    TreeNode* root = new TreeNode(INT_MIN);
    //root->left = new TreeNode(INT_MAX);
    //root->right = new TreeNode(15);
    //root->right->right = new TreeNode(20);
    //root->right->left = new TreeNode(11);
    printInorder(root);
    cout << endl;

    cout << isValidBST(root);
    deleteTree(root);
    return 0;
}
