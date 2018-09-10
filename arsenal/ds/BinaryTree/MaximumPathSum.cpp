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


// Calculate the maximum sum of all paths.
// A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
// The path does not need to go through the root.
//
// 注意这题中的路径可以从任意节点开始到任意节点结束，不一定是叶子节点，所以不同于编程之美3.8求距离最远的两个节点'LongestPath'

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
