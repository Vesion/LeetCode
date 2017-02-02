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
        dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (!root) return;
        path += (path.empty() ? "" : "->") + to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        if (root->left) dfs(root->left, path, res);
        if (root->right) dfs(root->right, path, res);
    }
};


int main() {
    return 0;
}
