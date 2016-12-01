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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (!root->left && !root->right) {
            res.push_back(path + to_string(root->val));
            return;
        }
        if (root->left) dfs(root->left, path + to_string(root->val) + "->", res);
        if (root->right) dfs(root->right, path + to_string(root->val) + "->", res);
    }
};

int main() {
    Solution s;
    return 0;
}
