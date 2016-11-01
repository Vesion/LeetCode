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
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* successor = findMinNode(root->right); // find the inorder successor (the minimal node in right subtree)
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
private:
    TreeNode* findMinNode(TreeNode* root) {
        if (root->left) return findMinNode(root->left);
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}
