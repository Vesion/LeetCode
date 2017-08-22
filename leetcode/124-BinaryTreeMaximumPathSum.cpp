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

// similar to 053-MaximumSumSubarray, but here is a binary tree
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        postorder(root, res);
        return res;
    }

    int postorder(TreeNode* root, int& res) {
        if (!root) return 0;
        // get path sum from left and right subtrees
        // if left(right) subtree's sum < 0, we don't neet it any more
        int left = max(0, postorder(root->left, res));
        int right = max(0, postorder(root->right, res));
        res = max(res, left+right+root->val);
        return root->val + max(left, right);
    }
};


int main() {
    return 0;
}

