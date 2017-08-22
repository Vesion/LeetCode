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
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (!root) root = node;
        else if (node->val < root->val) root->left = insertNode(root->left, node);
        else root->right = insertNode(root->right, node);
        return root;
    }   
};

int main() {
    Solution s;
    return 0;
}
