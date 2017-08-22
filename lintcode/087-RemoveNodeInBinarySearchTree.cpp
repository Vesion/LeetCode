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
    
    TreeNode* findMinNode(TreeNode* root) {
        if (root->left) return findMinNode(root->left);
        return root;
    }


    TreeNode* removeNode(TreeNode* root, int value) {
        if (!root) return NULL;

        if (root->val > value) {
            root->left = removeNode(root->left, value); 
        }
        else if (root->val < value) {
            root->right = removeNode(root->right, value);
        }
        else { // find the node needed to be deleted
            if (!root->left) { // no left child
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if (!root->right) { // no right child
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else { // has both children
                TreeNode* successor = findMinNode(root->right); // find the inorder successor (the minimal node in right subtree)
                root->val = successor->val; // replace the root with its inorder successor
                root->right = removeNode(root->right, successor->val); // delete its inorder successor recursively
            }
        }

        return root;
    }
};

int main() {
    Solution s;
    return 0;
}
