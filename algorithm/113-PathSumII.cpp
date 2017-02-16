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
        dfs(root, sum, path, res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == 0) res.push_back(path);
        if (root->left) dfs(root->left, sum, path, res);
        if (root->right) dfs(root->right, sum, path, res);
        path.pop_back();
    }
};


int main() {
    return 0;
}
