#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


// Maximum depth
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


// Minimum depth, is not same with maximum depth
// becase tree like [1, 2], should return 2, not 1
int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(2);
    //root->left->left = new TreeNode(3);
    cout << maxDepth(root);
    cout << minDepth(root);
    return 0;
}
