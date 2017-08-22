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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false; // a path must end with a leaf node
        if (!root->left && !root->right) return sum == root->val;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};


int main() {
    return 0;
}
