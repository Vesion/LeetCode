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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        // get path sum from left child and right child respectively
        // ensure them no smaller than 0, because the path can start from any node (not necessarily leaf node)
        int left = max(0, dfs(root->left, res));
        int right = max(0, dfs(root->right, res));
        res = max(res, left+right+root->val);
        return root->val + max(left, right);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(-1);
    cout << s.maxPathSum(root) << endl;;
    return 0;
}

