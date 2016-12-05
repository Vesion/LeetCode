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


// Solution 1 : iterative
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;

        // these two situations can be merged into one loop :)
        TreeNode* suc = NULL;
        while (root) {
            if (root->val > p->val) {
                suc = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return suc;
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
