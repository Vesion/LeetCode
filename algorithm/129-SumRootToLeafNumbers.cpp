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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int cur) {
        if (!root) return 0;
        if (!root->left && !root->right)
            return cur*10 + root->val;
        return dfs(root->left, cur*10+root->val) + dfs(root->right, cur*10+root->val);
    }
};

int main() {
    Solution s;
    return 0;
}

