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


// Determine if a binary tree is height balanced


// bootom up solution, O(n) time
// much faster than the O(n^2) top down solution

int depth(TreeNode* root) {
    if (!root) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    if (left == -1 || right == -1 || abs(left-right) > 1) return -1;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return depth(root) != -1;
}


int main() {
    return 0;
}
