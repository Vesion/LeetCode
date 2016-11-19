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

// bottom-up, O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == -1 || right == -1 || abs(left-right) > 1) return -1;
        return max(left, right) + 1;
    }
};

int main() {
    Solution s;
    return 0;
}

