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

// Solution 1 : dp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<TreeNode*>> dp(n+1);
        dp[0] = {NULL};
        dp[1] = {new TreeNode(1)};
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (TreeNode* left : dp[j]) {
                    for (TreeNode* right : dp[i-j-1]) {
                        TreeNode* root = new TreeNode(j+1);
                        root->left = left;
                        root->right = cloneWithOffset(right, j+1); // add j+1 offset to nodes in right subtree
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    TreeNode* cloneWithOffset(TreeNode* root, int offset) {
        if (!root) return root;
        TreeNode* node = new TreeNode(root->val + offset);
        node->left = cloneWithOffset(root->left, offset);
        node->right = cloneWithOffset(root->right, offset);
        return node;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int start, int end) {
        if (start > end) return {NULL};
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            for (TreeNode* left : dfs(start, i-1)) {
                for (TreeNode* right : dfs(i+1, end)) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

