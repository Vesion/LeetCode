#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Page 324
// Give a BST, convert it to a sorted double list.

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* convert(TreeNode* root) {
        TreeNode* pre = NULL;
        inorder(root, pre);
        while (root->left) root = root->left;
        return root;
    }

    void inorder(TreeNode* root, TreeNode*& pre) {
        if (!root) return;
        inorder(root->left, pre);
        if (pre) {
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        inorder(root->right, pre);
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(20);

    TreeNode* head = s.convert(root);
    for (auto p = head; p; p = p->right) {
        cout << p->val << " ";
    }
    cout << endl;

    TreeNode* tail = head;
    while (tail->right) tail = tail->right;
    for (auto p = tail; p; p = p->left) {
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}
