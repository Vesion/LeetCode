#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

// solution 1 : according to definition of height-balanced tree
// compare left-subtree's height with right-subtree's
// waste time because of repetitive calculating height in recursion
int heightOf(TreeNode* root) {
    if (!root) return 0;
    return max(heightOf(root->left), heightOf(root->right)) + 1;
}

bool isBalanced_trivial(TreeNode* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (abs(heightOf(root->left) - heightOf(root->right)) <= 1 && isBalanced_trivial(root->left) && isBalanced_trivial(root->right)) return true;
    return false;
}

// solution 2 : improve solution1, faster
// save time with prune, skillful
int depth(TreeNode* root) { // return the height of root if root is a balanced tree, otherwise return -1
    if (!root) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    if (left < 0 || right < 0 || abs(left-right) > 1) return -1; // prune!
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return depth(root) >= 0;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    cout << isBalanced(root) << endl;
    deleteTree(root);
    return 0;
}
