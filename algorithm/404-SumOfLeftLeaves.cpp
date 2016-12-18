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
        return dfs(root, false);
    }

    int dfs(TreeNode* root, bool left) {
        if (!root) return 0;
        if (!root->left && !root->right && left) return root->val;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};

int main() {
    Solution s;
    return 0;
}

