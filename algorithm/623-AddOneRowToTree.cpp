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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return new TreeNode(v);
        if (d == 1) {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        preorder(root, 1, v, d);
        return root;
    }
    
    void preorder(TreeNode* root, int curDepth, int value, int targetDepth) {
        if (!root) return;
        if (curDepth < targetDepth-1) {
            preorder(root->left, curDepth+1, value, targetDepth);
            preorder(root->right, curDepth+1, value, targetDepth);
        }
        else if (curDepth == targetDepth-1) {
            TreeNode *left = root->left, *right = root->right;
            root->left = new TreeNode(value);
            root->right = new TreeNode(value);
            root->left->left = left;
            root->right->right = right;
        }
    }
};


int main() {
    return 0;
}
