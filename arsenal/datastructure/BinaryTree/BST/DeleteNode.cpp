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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            TreeNode* next = findnext(root->right);
            root->val = next->val;
            root->right = deleteNode(root->right, next->val);
        }
        return root;
    }

    TreeNode* findnext(TreeNode* root) {
        while (root->left) root = root->left;
        return root;
    }
};


int main() {
    return 0;
}


