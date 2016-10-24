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
    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        int result = 0;
        if (sum == root->val) ++result;
        result += dfs(root->left, sum-root->val);
        result += dfs(root->right, sum-root->val);
        return result;
    }

    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

int main() {
    Solution s;
    return 0;
}
