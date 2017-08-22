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
    int sumOfLeftLeaves(TreeNode* root) {
        return preorder(root, false);
    }
    
    int preorder(TreeNode* root, bool left) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            if (left) return root->val;
            else return 0;
        }
        return preorder(root->left, true) + preorder(root->right, false);
    }
};


int main() {
    return 0;
}
