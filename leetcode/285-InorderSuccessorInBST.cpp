#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


// Successor:
//      1. If p has right subtree, its successor is the left most one in his right subtree;
//      2. Else, go from root to p, find the lowest one which is larger than p (left turn).
// We can combine these two steps into one pass.


// Solution 1 : iterative
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        TreeNode *pre = NULL, *cur = root;
        while (cur) {
            if (cur->val > p->val) {
                pre = cur;
                cur = cur->left;
            } else cur = cur->right;
        }
        return pre;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        if (root->val > p->val) {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        } else {
            return inorderSuccessor(root->right, p);
        }
    }
};


int main() {
    return 0;
}
