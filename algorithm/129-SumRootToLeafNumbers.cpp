#include <iostream>
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

int dfs(TreeNode* root, int sum) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return sum * 10 + root->val;
    return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    cout << sumNumbers(root);

    deleteTree(root);
    return 0;
}
