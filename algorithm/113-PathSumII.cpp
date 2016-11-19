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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, root, sum);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) 
            res.push_back(path);
        if (root->left) dfs(res, path, root->left, sum-root->val);
        if (root->right) dfs(res, path, root->right, sum-root->val);
        path.pop_back();
    }
};

int main() {
    Solution s;
    return 0;
}

